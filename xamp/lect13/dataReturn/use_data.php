<?php 

include("get_data.php");
echo "Get_Data";
echo "<pre>";
print_r($arr);
echo "</pre>";

$arr2=include("return_data.php");
echo "Return Data";
echo "<pre>";
print_r($arr2);
echo "</pre>";
?>
