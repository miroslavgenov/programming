<?php 
    if(isset($_POST['fname']) && !empty($_POST['fname'])){
        setcookie('fname',$_POST['fname'],time()+20);
    }
    elseif(isset($_COOKIE['fname'])){
        $name=$_COOKIE['fname'];
        echo "<p>Hey you have been here ".$name  ."</p>";
    }
?>
<form method="post" >
    <h3>Enter you name</h3> 
    <input type="text" name="fname">
    <input type="submit" value="Send">    
</form>
<a href="page1.php">Next Page</a>