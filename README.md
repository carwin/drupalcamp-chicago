This repo contains the slides for the DrupalCamp Chicago Presentation: Tools For Rapid Drupal Deployment given by @carwin and @jackinloadup. They have been re-formatted into markdown for easier reading. Enjoy!

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


Features!
=========
![figure 3](http://i.imgur.com/cofC8.png)


--------------------------------------------------------------------------


##What Is A Feature?
![figure 4](http://i.imgur.com/vCpom.png)

Example Features:
* A news and events section
* A blog
* A twitter aggregator


--------------------------------------------------------------------------


##What Can Be Exported?
* Content Types
* Fields
* Menus
* Taxonomies
* Text Formats
* WYSIWYG styles
* User roles and permissions
* Views
* System Variables (via Strongarm)
* Panels
* Etc...!


--------------------------------------------------------------------------


##Who Would Want This?

* People looking for quick and simple reuse of the same functionality
    * Freelancers
    * Sweatshops
* People looking to use Drupal in a dev, stage, production environment
    * Businesses
    * Best Practice seekers


--------------------------------------------------------------------------


##Features UI Screenshots:
![figure 5](http://i.imgur.com/aA73Y.png)
![figure 6](http://i.imgur.com/U1DGp.png)
![figure 7](http://i.imgur.com/AfofO.png)


--------------------------------------------------------------------------


DRUSH
=====
![figure 8](http://pawsru.org/fc/src/fc75643_126312599399.png)
(your face after you use drush the first time)


--------------------------------------------------------------------------


##Things Drush Can Do For Us

###Download Drupal
<pre>> drush dl drupal</pre> or <pre>> drush dl drupal-7.13</pre>
###Download Modules
<pre>> drush dl contrib_module</pre>
###Enable Modules
<pre>> drush en contrib_module</pre>
###Evaluate PHP
<pre>> drush ev "print 'woot';"</pre>


--------------------------------------------------------------------------


##Why `drush ev` Is Useful

###This is a fake DBTNG query
<pre>
$query = db_delete('users')            
->notExists(db_select('fields','f')
->fields('some_field') 
->where('f.fid' = 'users.uid'))
->execute();
</pre>
###`drush ev` would give us this fake MySQL
<pre>
DELETE FROM {users} WHERE ( 
NOT EXISTS (blah blah blah blah));
</pre>


--------------------------------------------------------------------------


##Other Things Drush Can Do:
* sync databases with remote servers
* sync files with remote servers
* update Drupal core
* set site variables
* clear caches


--------------------------------------------------------------------------


Drush Make
==========
![figure 9](http://imgur.com/83yrb.jpg)


--------------------------------------------------------------------------


##How Can I Use Drush Make?
<pre>
    drush make /path/to/my-install-profile-file.make
    drush make http://example.com/my-install-profile-file.make
    drush make http://github.com/my-install-profile-file.make
</pre>

####More Info
<pre>drush help make</pre>


--------------------------------------------------------------------------


##What Are Makefiles Anyway?
These can define makefiles & be included in make files:
* install profiles
* themes
* modules
* libraries
* features


--------------------------------------------------------------------------


##Makefiles Work Recursively!
* myplatform.build
    * Drupal 7.17
    * my-platform-install-profile.make
        * views
        * entity
        * token
        * my-slideshow-feature
            * my-slideshow-feature.make
                * views_slideshow
                * jquery.cycle


--------------------------------------------------------------------------


##Makefile Structure
####my-slideshow-feature.info
<pre>
    name = My Slideshow Feature
    description = Creates a content type that.
    core = 7.x

    dependencies[] = views_slideshow
</pre>

####my-slideshow-feature.make
<pre>
    core = 7.x
    api = 2

    projects[] = views
    projects[] = views_slideshow

    libraries[jquery.cycle][type] = "libraries"
    libraries[jquery.cycle][download][type] = "file"
    libraries[jquery.cycle][download][url] = "https://raw.github.com/malsup/cycle/master/jquery.cycle.all.js"
</pre> 


--------------------------------------------------------------------------


##Where Can Makefiles Download Their Resources From?

* Drupal.org
* Features Servers (fserver)
* Version Control Systems (git/svn/etc...)
* FTP


--------------------------------------------------------------------------


#Resources#

###Installation Profiles###
- [How to Write a Drupal 7 Installation Profile](http://drupal.org/node/1022020)
- [Profiler](http://drupal.org/project/profiler)

###Features##
- [Features](http://drupal.org/project/features)

###Drush & Makefiles###
- [Drush](http://drupal.org/project/drush)
- [Drush Resources](http://www.drush.org/resources)
- [Workflow and tools for developing with install profiles and Drush Make](http://www.designhammer.com/blog/workflow-and-tools-developing-install-profiles-and-drush-make)

###Going To The Next Level###
- [Zero-touch Drupal deployment with Jenkins, Aegir, Git, Fabric and Drush](http://mig5.net/content/zero-touch-drupal-deployment-jenkins-aegir-git-fabric-and-drush)


#Presenters#
###![Carwin Young](http://www.gravatar.com/avatar/97c966c7c078ed7a0f1e494a786f1aa0.png) Carwin Young ###
*Lullabot*<br/>
[carwin](http://drupal.org/user/487058) on Drupal.org


###![Lucas Riutzel](http://www.gravatar.com/avatar/fd5ba46854d25e47eb32f2cf69c467ae.png) Lucas Riutzel ###
*Kanakuk Ministries*<br/>
[jackinloadup](http://drupal.org/user/453722) on Drupal.org
