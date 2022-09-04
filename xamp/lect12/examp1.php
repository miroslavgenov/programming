<?php  

echo "preg_match(pattern,string)<br>";

$pattern = "/Java/";
// we will use pattern1  becouse we will compare the 
// url addresses
$pattern1= "~php~";


$s1="I love Java";
$s2="Javascript is my favourite langueage";

//
echo "preg_match($pattern,$s1)<br>";
echo preg_match($pattern,$s1)."<br>";
//
echo "preg_match($pattern,$s2)<br>";
echo preg_match($pattern,$s2)."<br>";
//
echo "preg_match($pattern1,$s1)<br>";
echo preg_match($pattern1,$s1)."<br>";
//
echo "preg_match($pattern1,$s2)<br>";
echo preg_match($pattern1,$s2)."<br>";

?>
