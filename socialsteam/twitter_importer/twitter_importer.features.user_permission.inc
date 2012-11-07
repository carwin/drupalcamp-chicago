<?php
/**
 * @file
 * twitter_importer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function twitter_importer_user_default_permissions() {
  $permissions = array();

  // Exported permission: access toolbar.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'Editor',
      1 => 'administrator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'Editor',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'Editor',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any tweet content.
  $permissions['delete any tweet content'] = array(
    'name' => 'delete any tweet content',
    'roles' => array(
      0 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any tweet content.
  $permissions['edit any tweet content'] = array(
    'name' => 'edit any tweet content',
    'roles' => array(
      0 => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
