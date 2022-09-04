<?php

try {
   $conn = new PDO("mysql:host=localhost;dbname=ajax;charset=utf8", "root", "");
   $query=   $conn->prepare("SELECT * FROM   users");
   $query->execute();
   $resultJSON = json_encode($query->fetchAll(), JSON_UNESCAPED_UNICODE);
   echo $resultJSON ;
}
catch(PDOException $e)
  {
    echo "Error: " . $e->getMessage();
 }

?>