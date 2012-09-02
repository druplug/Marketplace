<?php

/**
 * Views for the default seller UI.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_seller_ui_views_default_views() {
  $views = array();

  // Seller profile admin list at admin/commerce/seller-profiles.
  $view = new view;
  $view->name = 'commerce_seller_profiles';
  $view->description = 'A list of seller profiles of all types.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_seller_profile';
  $view->human_name = 'Seller profiles';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Seller profiles';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_seller_profile entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'profile_id' => 'profile_id',
    'name' => 'name',
    'type' => 'type',
    'status' => 'status',
    'edit_seller_profile' => 'edit_seller_profile',
    'delete_seller_profile' => 'edit_seller_profile',
  );
  $handler->display->display_options['style_options']['default'] = 'profile_id';
  $handler->display->display_options['style_options']['info'] = array(
    'profile_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_seller_profile' => array(
      'align' => '',
      'separator' => '&nbsp;&nbsp;&nbsp;',
      'empty_column' => 0,
    ),
    'delete_seller_profile' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* No results behavior: Commerce Seller Profile: Empty text */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/commerce/seller-profiles/add';
  /* Relationship: Commerce Seller Profile: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Commerce Seller Profile: Profile ID */
  $handler->display->display_options['fields']['profile_id']['id'] = 'profile_id';
  $handler->display->display_options['fields']['profile_id']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['fields']['profile_id']['field'] = 'profile_id';
  $handler->display->display_options['fields']['profile_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['profile_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['profile_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['profile_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['profile_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['profile_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['profile_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['profile_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['profile_id']['link_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Commerce Seller Profile: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_profile'] = 0;
  /* Field: Commerce Seller Profile: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['type'] = 'active-disabled';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Commerce Seller Profile: Edit link */
  $handler->display->display_options['fields']['edit_seller_profile']['id'] = 'edit_seller_profile';
  $handler->display->display_options['fields']['edit_seller_profile']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['fields']['edit_seller_profile']['field'] = 'edit_seller_profile';
  $handler->display->display_options['fields']['edit_seller_profile']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_seller_profile']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_seller_profile']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_seller_profile']['empty_zero'] = 0;
  /* Field: Commerce Seller Profile: Delete link */
  $handler->display->display_options['fields']['delete_seller_profile']['id'] = 'delete_seller_profile';
  $handler->display->display_options['fields']['delete_seller_profile']['table'] = 'commerce_seller_profile';
  $handler->display->display_options['fields']['delete_seller_profile']['field'] = 'delete_seller_profile';
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_seller_profile']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_seller_profile']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_seller_profile']['empty_zero'] = 0;
  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'page_1');
  $handler->display->display_options['path'] = 'admin/commerce/seller-profiles/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'seller profiles';
  $handler->display->display_options['tab_options']['description'] = 'Manage seller profiles and profile types in the store.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['commerce_seller_profiles'] = array(
    t('Defaults'),
    t('Seller profiles'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Profile owner'),
    t('Profile ID'),
    t('Name'),
    t('User'),
    t('Type'),
    t('Status'),
    t('Operations'),
    t('Delete link'),
    t('Filter by names containing'),
    t('Admin page'),
  );

  $views[$view->name] = $view;

  return $views;
}
