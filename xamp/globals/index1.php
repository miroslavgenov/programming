<?php 
    #var_dump($_POST);
    if(isset($_POST['nam']) && $_POST['nam']!=''){
        echo "<pre>";
        print_r($_POST);
        echo "</pre>";
    }
?>
<form action="index1.php" method="post">
    <h1>Post</h1>
    <label for="name">name <input type="text" name="nam" id=""></label>
    <input type="submit" value="Send">
</form>
