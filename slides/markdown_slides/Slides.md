Tools For Rapid Drupal Deployment
=================================
_install profiles_ - _features_ - _drush_ - _drush make_



##What Is Rapid Drupal Deployment?
* Building re-usable platforms rather than building one-off sites
* Focusing on repeatable configurations to launch the same platform across multiple environments.
* Separating our configuration from our content (as much as possible).


![figure 1](http://i.imgur.com/92VnH.png)


--------------------------------------------------------------------------


##Why Would You Do This?
* It saves time.
* We like things DRY.
* It saves time.
* Re-usability is good.
* *It saves time.*

(spot the conundrum!)


--------------------------------------------------------------------------


Installation Profiles
=====================
![figure 2](http://i.imgur.com/iYnl1.png)


--------------------------------------------------------------------------


##What Is An Installation Profile?
* Configuration
* Dependencies
* Modifications
* AKA "Marching Orders"


--------------------------------------------------------------------------


##What Do We Need To Create One?
* A *.info* file - to describe the various module dependencies you want to enforce.
* A *.install* file - to set your variables and <i>Configure All The Things ™</i>
* A *.profile* file - to use various Drupal hoooks like `hook_form_alter()` or `hook_image_default_styles()`


--------------------------------------------------------------------------


##Sample.info
<pre>
name = Great Profile!
description = Really, this is better than those other profiles.
core = 7.x

; Core modules
dependencies[] = php
dependencies[] = rdf
dependencies[] = block

; Contrib modules
dependencies[] = pathauto
dependencies[] = menu_block
dependencies[] = token
</pre>


--------------------------------------------------------------------------


##Sample.install
<pre>
function sample_install() {
    
    // Turn off comments for basic pages
    variable_set('comment_page', COMMENT_NODE_HIDDEN);
    
    // No user pictures
    variable_set('user_pictures', 0);
    
    // Theme stuff!
    variable_set('theme_default', 'bartik');
    variable_set('admin_theme', 'rubik');
    variable_set('node_admin_theme', '1');
    theme_enable('tao', 'rubik'));
}
</pre>


--------------------------------------------------------------------------


##Sample.profile
<pre>
function sample_form_alter(&amp;$form, $form_state, $form_id) {
  
  	switch($form_id) {
  
    	case "install_configure_form":
    		$form['admin_account']['account']['name]['#default_value'] = 'admin'
    		$form['admin_account']['account']['mail']['#default_value'] = 'joe@shmoe.com'
       		break;
	}

}
</pre>


--------------------------------------------------------------------------
