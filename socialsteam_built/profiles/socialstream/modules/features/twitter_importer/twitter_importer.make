core = 7.x
api = 2

defaults[projects][subdir] = "contrib"

projects[] = feeds
projects[] = job_scheduler
projects[] = link
projects[] = views
projects[] = views_bulk_operations
projects[] = rules
projects[] = entity
projects[] = services
projects[] = services_views
projects[] = twitter

projects[feeds_jsonpath_parser][download][type] = "git"
projects[feeds_jsonpath_parser][download][url] = "http://git.drupal.org/project/feeds_jsonpath_parser.git"
projects[feeds_jsonpath_parser][download][revision] = "b0e12cd7c8b4ac7e55cd90617494316a26fc16e6"
projects[feeds_jsonpath_parser][patch][860974] = "http://drupal.org/files/incorrect_string_value-1824506.patch"

; Libraries
libraries[jsonpath][download][type] = "file"
libraries[jsonpath][download][url] = "http://jsonpath.googlecode.com/files/jsonpath-0.8.1.php"
libraries[jsonpath][destination] = "modules/contrib"
libraries[jsonpath][directory_name] = "feeds_jsonpath_parser"
