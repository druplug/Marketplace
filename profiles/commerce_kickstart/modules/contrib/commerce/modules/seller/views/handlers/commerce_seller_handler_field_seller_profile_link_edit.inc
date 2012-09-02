<?php

/**
 * Field handler to present a seller profile edit link.
 */
class commerce_seller_handler_field_seller_profile_link_edit extends commerce_seller_handler_field_seller_profile_link {
  function construct() {
    parent::construct();

    $this->additional_fields['type'] = 'type';
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // Ensure the user has access to edit this profile.
    $profile = commerce_seller_profile_new();
    $profile->profile_id = $this->get_value($values, 'profile_id');
    $profile->type = $this->get_value($values, 'type');
    $profile->uid = $this->get_value($values, 'uid');

    if (!commerce_seller_profile_access('update', $profile)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    return l($text, 'admin/commerce/seller-profiles/' . $profile->profile_id . '/edit', array('query' => drupal_get_destination()));
  }
}
