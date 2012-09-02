<?php

/**
 * @file
 * Page callbacks and form builder functions for administering seller profiles.
 */


/**
 * Menu callback: display a list of seller profile types that the user can create.
 */
function commerce_seller_ui_seller_profile_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  // Bypass the admin/commerce/sellers/profiles/add listing if only one
  // seller profile available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }

  return theme('seller_profile_add_list', array('content' => $content));
}

/**
 * Displays the list of available seller profile types for profile creation.
 *
 * @ingroup themeable
 */
function theme_seller_profile_add_list($variables) {
  $content = $variables['content'];
  $output = '';

  if ($content) {
    $output = '<dl class="commerce-seller-profile-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer seller profile types')) {
      $output = '<p>' . t('You have not enabled modules defining any seller profile types yet.') . '</p>';
    }
    else {
      $output = '<p>' . t('No seller profile types have been enabled yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Form callback wrapper: create or edit a seller profile.
 *
 * @param $profile
 *   The seller profile object being edited by this form.
 *
 * @see commerce_seller_seller_profile_form()
 */
function commerce_seller_ui_seller_profile_form_wrapper($profile) {
  // Add the breadcrumb for the form's location.
  commerce_seller_ui_set_breadcrumb();

  // Include the forms file from the seller module.
  module_load_include('inc', 'commerce_seller', 'includes/commerce_seller_profile.forms');

  return drupal_get_form('commerce_seller_ui_seller_profile_form', $profile);
}

/**
 * Form callback wrapper: confirmation form for deleting a seller profile.
 *
 * @param $profile
 *   The seller profile object being deleted by this form.
 *
 * @see commerce_seller_seller_profile_delete_form()
 */
function commerce_seller_ui_seller_profile_delete_form_wrapper($profile) {
  // Add the breadcrumb for the form's location.
  commerce_seller_ui_set_breadcrumb(TRUE);

  // Include the forms file from the seller module.
  module_load_include('inc', 'commerce_seller', 'includes/commerce_seller_profile.forms');

  return drupal_get_form('commerce_seller_ui_seller_profile_delete_form', $profile);
}
