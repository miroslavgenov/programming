<?php 

$connect = new PDO("mysql:host=localhost;dbname=lect11_ex2","root","");
$connect->exec("set names utf8");
$query = "SELECT * FROM data";
$str= $connect->prepare($query);
$str->execute();
// return all the result fetchAll and return indexex from the table
// :: obrushtame se kum metod na klass
$result = $str->fetchAll(PDO::FETCH_ASSOC);

echo "<pre>";

print_r($result);
echo "</pre>"


?>