<?php

if($_POST['msg1']){
    $name=$_POST['msg1'];
}

try {
   $conn = new PDO("mysql:host=localhost;dbname=ajax; charset=utf8", "root", "");
    $query="INSERT INTO users(name) VALUES(:name)";
    $str=$conn->prepare($query);
    $str->bindParam(':name',$name);
    $str->execute();
}catch(PDOException $e){
    echo "$e->getMessage()";
}

?>