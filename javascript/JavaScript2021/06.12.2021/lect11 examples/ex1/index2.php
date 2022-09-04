<?php 

if(isset($_GET['id'])){
    $id=$_GET['id'];
    $file = file_get_contents("pages/{$id}.txt");
    echo $file."<br>";
}



?>



<?php 
for($i=1;$i<4;$i++){
    // echo "<a href='index2.php?id=$i'>T $i</a><br>";
    echo  "<a href=\"index2.php?id=$i\">T$i</a> <nbsp>";
}
?>










