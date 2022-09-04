<?php 
  return array(
     "yourName/users/([0-9]+)"=> "users/view/$1",  // метод actionView на класа UsersController
	  "yourName/users/([а-яА-Я]+)"=> "users/view/$1",  // метод actionView на класа UsersController
      "yourName/users/add"=> "users/add",  // метод actionAdd на класа UsersController
  	 "yourName/users"=> "users/list",  // метод actionList на класа UsersController
  	 "yourName/admins"=> "admin/index" // метод actionIndex на класа AdminController
  );