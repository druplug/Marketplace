<?php

/**
 * @file
 * Provides metadata for the seller profile entity.
 */

/**
 * Implements hook_entity_property_info().
 */
function commerce_seller_entity_property_info() {
  $info = array();

  // Add meta-data about the basic commerce_seller_profile properties.
  $properties = &$info['commerce_seller_profile']['properties'];

  $properties['profile_id'] = array(
    'label' => t('Profile ID'),
    'description' => t('The internal numeric ID of the seller profile.'),
    'type' => 'integer',
    'schema field' => 'profile_id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The type of the seller profile.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_seller_profile entities',
    'options list' => 'commerce_seller_profile_type_options_list',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['uid'] = array(
    'label' => t('User ID'),
    'type' => 'integer',
    'description' => t("The unique ID of the user the seller profile belongs to."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_seller_profile entities',
    'clear' => array('user'),
    'schema field' => 'uid',
  );
  $properties['user'] = array(
    'label' => t('User'),
    'type' => 'user',
    'description' => t("The user the seller profile belongs to."),
    'getter callback' => 'commerce_seller_profile_get_properties',
    'setter callback' => 'commerce_seller_profile_set_properties',
    'setter permission' => 'administer commerce_seller_profile entities',
    'required' => TRUE,
    'computed' => TRUE,
    'clear' => array('uid'),
  );
  $properties['status'] = array(
    'label' => t('Status'),
    'description' => t('Whether or not the seller profile is active.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_seller_profile entities',
    'type' => 'boolean',
    'schema field' => 'status',
  );
  $properties['created'] = array(
    'label' => t('Date created'),
    'description' => t('The date the seller profile was created.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_seller_profile entities',
    'schema field' => 'created',
  );
  $properties['changed'] = array(
    'label' => t('Date updated'),
    'description' => t('The date the seller profile was last updated.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_seller_profile entities',
    'schema field' => 'changed',
  );

  return $info;
}
