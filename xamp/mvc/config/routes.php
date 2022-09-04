<?php 

return array(
    "mvc/users/([0-9]+)"=>"users/view/$1",
    "mvc/users/([а-яА-Я]+)"=>"users/view/$1",
    "mvc/users/add"=>"users/add",
    "mvc/users"=>"users/list",
    "mvc/admins"=>"admin/index"

);

?>