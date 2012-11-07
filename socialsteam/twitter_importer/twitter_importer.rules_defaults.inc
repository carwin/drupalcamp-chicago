<?php
/**
 * @file
 * twitter_importer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function twitter_importer_default_rules_configuration() {
  $items = array();
  $items['rules_flag_retweets'] = entity_import('rules_config', '{ "rules_flag_retweets" : {
      "LABEL" : "Flag ReTweets",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "twitter" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "node" ], "type" : "node" } },
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "tweet" : "tweet" } } } },
        { "text_matches" : { "text" : [ "node:body:value" ], "match" : "RT", "operation" : "starts" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-is-retweet" ], "value" : "yes" } }
      ]
    }
  }');
  return $items;
}
