<?php 

session_start();

$a2=$_POST['q2'];
$_SESSION['q2'] = $a2;

?>



<form action="result.php" method="post">
        <input type="text" name="q3" id="">
        <input type="submit" value="Sub">
</form>