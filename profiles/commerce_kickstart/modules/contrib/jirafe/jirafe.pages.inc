<?php

/**
 * Page callback: render an iframe that will load the dashboard.
 */
function _jirafe_dashboard_page() {
  $output['jirafe']['#attached']['css'][] = drupal_get_path('module', 'jirafe') . '/jirafe.css';
  $config = variable_get('jirafe_config');
  if (!empty($config['token']) && !empty($config['app_id'])) {
    $markup = theme('jirafe_dashboard', array('url' => url('admin/commerce/jirafe/inline')));
  }
  else {
    $markup = t('Your Jirafe account is not configured. If you already got your token and application ID, enter them <a href="@admin-url">here</a>. To open a Jirafe account visit !link', array('@admin-url' => url('admin/commerce/config/jirafe'), '!link' => variable_get('jirafe_create_account_link', l('Jirafe.com', 'http://www.jirafe.com'))));
  }
  $output['jirafe']['#markup'] = $markup;
  return $output;
}

/**
 * Page callback: render the dashboard itself.
 */
function _jirafe_dashboard_page_inline() {
  $config = variable_get('jirafe_config');

  $variables = array(
    'data' => array(
      'api_url' => 'https://api.jirafe.com/v1',
      'api_token' => $config['token'],
      'app_id' => $config['app_id'],
      'version' => 'magento-v0.3.0',
    ),
  );
  echo theme('jirafe_dashboard_iframe', $variables);

  return drupal_exit();
}
