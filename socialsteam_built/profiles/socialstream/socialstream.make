core = 7.x
api = 2

defaults[projects][subdir] = "contrib"

; Contrib
projects[] = ctools
projects[] = libraries
projects[] = strongarm
projects[] = token
projects[] = features
projects[] = responsive_bartik
projects[] = r4032login

; Features
projects[twitter_importer][type] = "module"
projects[twitter_importer][subdir] = "features"
projects[twitter_importer][download][type] = "git"
projects[twitter_importer][download][url] = "git@pub1:site/socialstream/twitter_importer"
projects[twitter_importer][download][branch] = 7.x-1.x
