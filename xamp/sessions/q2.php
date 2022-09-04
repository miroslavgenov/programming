<?php 
session_start();
$_SESSION['f_name']=$_POST['f_name'];
?>
<form action="q3.php" method="post">
    <input type="text" name="s_name" id="">
    <input type="submit" value="NEXT">
</form>
