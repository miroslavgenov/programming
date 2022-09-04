<?php 

// echo "HELLO FROM DATABASE <br>";



class DataBase{
    public static function connectDataBase(){
        // echo "xxxx<br>";
        // echo "data base Paramas<br>";
        $dbInfo = require_once(PATH."\\configs\\db_params.php");
        // echo "<pre>";
        // print_r($dbInfo);
        // echo "</pre>";
        $dbParams = "mysql:host={$dbInfo['host']};dbname={$dbInfo['dbname']};charset=utf8";
        // echo "$dbParams <br>";
        return new PDO($dbParams,$dbInfo['user'],$dbInfo['password']);
    }
}



?>