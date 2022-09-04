<?php 

$f = file("users.txt");
var_dump($f);

echo "<table>";
foreach($f as $el){
    echo "<tr>";
    $data = explode(",",$el);
    foreach($data as $d){
        echo "<td>$d</td>";
    }
    
    echo "</tr>";
}

echo "</table>";
?>

<style>
    table{
        background-color:blue;
    }
    td{
        background-color:white;
    }
    
</style>
