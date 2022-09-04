<?php 
    if(isset($_COOKIE['fname'])){
        $name=$_COOKIE['fname'];
        echo "<p> hello {$name} </p>" ;
    }
?>
<a href="index.php">Prev page</a>