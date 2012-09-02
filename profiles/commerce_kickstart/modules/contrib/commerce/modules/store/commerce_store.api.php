<?php

/**
 * @file
 * Hooks provided by the Store module.
 */

/**
 * Lets modules specify the path information expected by a uri callback.
 *
 * The Store module defines a uri callback for the store entity even though
 * it doesn't actually define any store menu items. The callback invokes this
 * hook and will return the first set of path information it finds. If the
 * Store UI module is enabled, it will alter the store entity definition to
 * use its own uri callback that checks commerce_store_uri() for a return
 * value and defaults to an administrative link defined by that module.
 *
 * This hook is used as demonstrated below by the Store Reference module to
 * direct modules to link the store to the page where it is actually displayed
 * to the user. Currently this is specific to nodes, but the system should be
 * beefed up to accommodate even non-entity paths.
 *
 * @param $store
 *   The store object whose uri information should be returned.
 *
 * @return
 *   Implementations of this hook should return an array of information as
 *   expected to be returned to entity_uri() by a uri callback function.
 *
 * @see commerce_store_uri()
 * @see entity_uri()
 */
function hook_commerce_store_uri($store) {
  // If the store has a display context, use it entity_uri().
  if (!empty($store->display_context)) {
    return entity_uri($store->display_context['entity_type'], $store->display_context['entity']);
  }
}

/**
 * Lets modules prevent the deletion of a particular store.
 *
 * Before a store can be deleted, other modules are given the chance to say
 * whether or not the action should be allowed. Modules implementing this hook
 * can check for reference data or any other reason to prevent a store from
 * being deleted and return FALSE to prevent the action.
 *
 * This is an API level hook, so implementations should not display any messages
 * to the user (although logging to the watchdog is fine).
 *
 * @param $store
 *   The store to be deleted.
 *
 * @return
 *   TRUE or FALSE indicating whether or not the given store can be deleted.
 *
 * @see commerce_store_reference_commerce_store_can_delete()
 */
function hook_commerce_store_can_delete($store) {
  // Use EntityFieldQuery to look for line items referencing this store and do
  // not allow the delete to occur if one exists.
  $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'commerce_line_item', '=')
    ->entityCondition('bundle', 'store', '=')
    ->fieldCondition('store', 'store_id', $store->store_id, '=')
    ->count();

  return $query->execute() > 0 ? FALSE : TRUE;
}
