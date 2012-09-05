<?php

/**
 * @file
 * Forms for creating, editing, and deleting stores.
 */


/**
 * Form callback: create or edit a store.
 *
 * @param $store
 *   The store object to edit or for a create form an empty store object.
 */
function commerce_store_store_form($form, &$form_state, $store) {
  $language = !empty($store->language) ? $store->language : LANGUAGE_NONE;

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'commerce_store') . '/includes/commerce_store.forms.inc';

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $store->title,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements.
  $form_state['commerce_store'] = $store;
  field_attach_form('commerce_store', $store, $form, $form_state, $language);

  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#description' => t('Disabled stores will not be visible to end users.'),
    '#options' => array(
      '1' => t('Active'),
      '0' => t('Disabled'),
    ),
    '#default_value' => $store->status,
    '#required' => TRUE,
    '#weight' => 35,
  );

  $form['change_history'] = array(
    '#type' => 'fieldset',
    '#title' => t('Change history'),
    '#collapsible' => TRUE,
    '#collapsed' => empty($store->store_id),
    '#weight' => 50,
  );

  $form['change_history']['log'] = array(
    '#type' => 'textarea',
    '#title' => !empty($store->store_id) ? t('Update log message') : t('Creation log message'),
    '#rows' => 4,
    '#description' => t('Provide an explanation of the changes you are making. This will provide a meaningful history of changes to this store.'),
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // Simply use default language
  $form['language'] = array(
    '#type' => 'value',
    '#value' => $language,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save store'),
    '#submit' => array_merge($submit, array('commerce_store_store_form_submit')),
  );

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'commerce_store_store_form_validate';

  return $form;
}

/**
 * Validation callback for commerce_store_store_form().
 */
function commerce_store_store_form_validate($form, &$form_state) {
  $store = $form_state['commerce_store'];
  field_attach_form_validate('commerce_store', $store, $form, $form_state);

}

/**
 * Submit callback for commerce_store_store_form().
 */
function commerce_store_store_form_submit($form, &$form_state) {
  global $user;

  $store = &$form_state['commerce_store'];

  // Save default parameters back into the $store object.
  $store->title = $form_state['values']['title'];
  $store->status = $form_state['values']['status'];
  $store->language = $form_state['values']['language'];

  // Set the store's uid if it's being created at this time.
  if (empty($store->store_id)) {
    $store->uid = $user->uid;
  }

  // Trigger a new revision if the checkbox was enabled or a log message supplied.
  if ((user_access('administer commerce_store entities') && !empty($form_state['values']['revision'])) ||
    (!user_access('administer commerce_store entities') && !empty($form['change_history']['revision']['#default_value'])) ||
    !empty($form_state['values']['log'])) {
    $store->revision = TRUE;
    $store->log = $form_state['values']['log'];
  }

  // Notify field widgets.
  field_attach_submit('commerce_store', $store, $form, $form_state);

  // Save the store.
  commerce_store_save($store);

  // Redirect based on the button clicked.
  drupal_set_message(t('Store saved.'));
}

/**
 * Form callback: confirmation form for deleting a store.
 *
 * @param $store
 *   The store object to be deleted.
 *
 * @see confirm_form()
 */
function commerce_store_store_delete_form($form, &$form_state, $store) {
  $form_state['store'] = $store;

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'commerce_store') . '/includes/commerce_store.forms.inc';

  $form['#submit'][] = 'commerce_store_store_delete_form_submit';

  $content = entity_view('commerce_store', array($store->store_id => $store));

  $form = confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $store->title)),
    '',
    drupal_render($content) . '<p>' . t('Deleting this store cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for commerce_store_store_delete_form().
 */
function commerce_store_store_delete_form_submit($form, &$form_state) {
  $store = $form_state['store'];

  if (commerce_store_delete($store->store_id)) {
    drupal_set_message(t('%title has been deleted.', array('%title' => $store->title)));
    watchdog('commerce_store', 'Deleted store %title.', array('%title' => $store->title), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('%title could not be deleted.', array('%title' => $store->title)), 'error');
  }
}
