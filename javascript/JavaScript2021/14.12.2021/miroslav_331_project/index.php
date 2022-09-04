
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Miroslav 331</title>
    <style>
        body{
            text-align:center;
        }
        div{
            margin-top:-10%;
            
        }
        table{
            border-radius: 20px;
            border: 2px solid #333;
            box-shadow: 12px 12px 2px 1px rgba(0, 0, 255, .2);
        }

        thead{
            text-align:right;
            text-decoration: underline;
            font-size:20px
        }
        h4{
            text-align:left;
            color:red;
            
        }
        #tableCol{
            text-decoration: underline;
            
            
        }

    </style>
</head>
<body>
    <h1>Проект на Мирослав 331 СИ 13 </h1>
    <h3>Тема : Програмни езици</h3>

    <h3> <u>Адреси за въвждане:</u></h3>
    <b><p>http://localhost/miroslav_331_project/list/all</p>
    <p>http://localhost/miroslav_331_project/year/(\d+)</p>
    <p>http://localhost/miroslav_331_project/inforate/(\d+)</p>
    <p>http://localhost/miroslav_331_project/добави</p></b>

</body>
</html>

<?php 
 # quick way to display all errors/warnings
 ini_set('display_errors',1);
    
 #reports all php errors
 error_reporting(E_ALL);
 define('PATH',dirname(__FILE__));
 
require_once(PATH."\\components\\router.php");
include_once(PATH."\\components\\database.php");

$router = new Router();
$router->run();

?>
