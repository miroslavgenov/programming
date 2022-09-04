<?php
//echo "from server...";
if (isset ($_GET['name'])){
	$name=$_GET['name'];
}
if (isset ($_POST['name'])){
	$name=$_POST['name'];
}

try {
   $conn = new PDO("mysql:host=localhost;dbname=ajax;charset=utf8", "root", "");
   $query=$conn->prepare("SELECT * FROM   users WHERE name=:name");
   $query->bindParam(':name', $name);
   $query->execute();
   $result=json_encode ($query->fetch(), JSON_UNESCAPED_UNICODE );
   echo( $result) ;
}
catch(PDOException $e)
 {
    echo "Error: " . $e->getMessage();
}