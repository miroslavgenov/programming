<?php 

echo "GET";
echo "<pre>";
print_r( $_GET);
echo "</pre>";

// var1
$f = file_get_contents("pages/1.txt");
echo $f."<br>";
$f1= file("pages/1.txt");
print_r($f1);
?>






