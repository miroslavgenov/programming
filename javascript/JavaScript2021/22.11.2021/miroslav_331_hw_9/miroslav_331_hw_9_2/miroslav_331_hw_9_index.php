<?php

#add INFO TO DATABASE

if($_POST['myData']){
    #strstr() - Find the first occurrence of a string
    #strrpos() - Find the position of the last occurrence of a substring in a string
    $data = $_POST['myData']; 
    $title =  substr($data,0,strpos($data,','));
    $likes = substr(strstr($data,","),1);
    
}

try{

    $conn = new PDO("mysql:host=localhost;dbname=miroslav_331_hw_9_db; charset=utf8", "root", "");
    $query="INSERT INTO posts(title,likes) VALUES(:title,:likes)";
    $str=$conn->prepare($query);
    $str->bindParam(':title',$title);
    $str->bindParam(':likes',$likes);
    $str->execute();
    echo"done";

    
}catch(PDOException $e){
    echo $e->getMessage();
}
?>