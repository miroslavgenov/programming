<?php

//Oбщи настройки
ini_set('display_errors', 1);
error_reporting(E_ALL);

// основна папка на сайта
define('ROOT', dirname(__FILE__));

echo "Oсновна папка на сайта:".ROOT.'<br>';

//включване на необходимите компоненти
require_once(ROOT.'/components/router.php');
require_once(ROOT.'/components/database.php');


//създаване на обект Router и извикване
// на метода му run()
$router= new Router();
$router->run();

 ?>