<?php 
    try{
        $connect = new PDO("mysql:host=localhost; dbname=miroslav_331_hw_9_db;charset=utf8",'root','');
        $query = "SELECT * FROM posts";
        $str=$connect->prepare($query);
        $str->execute();
        $result=json_encode($str->fetchAll(),JSON_UNESCAPED_UNICODE);
        echo $result;
    }catch(PDOException $e){
        echo $e->getMessage();
    }


?>