<?php

/**
 * @file
 * Page callbacks and form builder functions for administering stores.
 */


/**
 * Menu callback: display a list of store types that the user can create.
 */
function commerce_store_ui_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  // Bypass the admin/commerce/stores/add listing if only one store type is
  // available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
}

/**
 * Form callback wrapper: create or edit a store.
 *
 * @param $store
 *   The store object being edited by this form.
 *
 * @see commerce_store_store_form()
 */
function commerce_store_ui_store_form_wrapper($store) {
  // Add the breadcrumb for the form's location.
  commerce_store_ui_set_breadcrumb();

  // Include the forms file from the Store module.
  module_load_include('inc', 'commerce_store', 'includes/commerce_store.forms');

  return drupal_get_form('commerce_store_ui_store_form', $store);
}

/**
 * Form callback wrapper: confirmation form for deleting a store.
 *
 * @param $store
 *   The store object being deleted by this form.
 *
 * @see commerce_store_store_delete_form()
 */
function commerce_store_ui_store_delete_form_wrapper($store) {
  // Add the breadcrumb for the form's location.
  commerce_store_ui_set_breadcrumb();

  // Include the forms file from the Store module.
  module_load_include('inc', 'commerce_store', 'includes/commerce_store.forms');

  return drupal_get_form('commerce_store_ui_store_delete_form', $store);
}
