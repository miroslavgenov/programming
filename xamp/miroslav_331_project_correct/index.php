<?php 
//
 # quick way to display all errors/warnings
 ini_set('display_errors',1);
    
 #reports all php errors
 error_reporting(E_ALL);
 define('PATH',dirname(__FILE__));
?>






<?php 
echo "
<!DOCTYPE html>
<html lang=\"en\">
<head>
    <meta charset=\"UTF-8\">
    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">
    
    <title>Miroslav Project</title></head>
    <style>".file_get_contents(PATH."\\styles\\style.css")."</style>
    
    <body>
        
        <h1>Проект на Мирослав 331 СИ 13 </h1>
        <h3>Тема : Програмни езици</h3>
        <h3> <u>Адреси за въвеждане:</u></h3>
       
    </body>
    </html>"
    
    ; 
?>


<?php 

require_once(PATH."\\components\\router.php");
include_once(PATH."\\components\\database.php");

$router = new Router();
$router->run();



?>