<?php 


if(isset($_GET['id'])){
    echo "GET = ";
    print_r($_GET);
    $id = $_GET['id'];
    $f= file_get_contents("pages/$id.txt");
    echo "<br>";
    echo nl2br($f);

}





?>


<br>
<a href="index1.php?id=1">T1</a>
<a href="index1.php?id=2">T2</a>
<a href="index1.php?id=3">T3</a>