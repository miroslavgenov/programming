<?php 

echo "\$_POST<br>";
var_dump($_POST);
session_start();
$a1 = $_POST['q1'];
$_SESSION['q1']=$a1;

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q2</title>
</head>
<body>
    <form action="q3.php" method="post">
        <input type="text" name="q2" id="">
        <input type="submit" value="Sub">
    </form>
</body>
</html>
