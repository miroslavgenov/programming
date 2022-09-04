<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hello from PHP</title>
</head>
<body>
<?PHP 
    

    $x1=1;
    $x2=2;
    $x=$x1+$x2;

    echo '<p>' .$x.'</p>';

    echo "<p> $x </p>";

    if($x < 10 ){
        echo "<10<br>";
    }else{
        echo ">10";
    }

    $x = ($x1>$x2)?$x1:$x2;
    echo "$x <br>";

    $x = '1';
    $x1=1;
    if($x == $x1){echo '='."<br>";}
    if($x === $x1){echo '='."<br>";}
    else{
        echo "!==<br>";
    }


    $x2= '1'+2;
    echo (3===$x2);
    





?>    


</body>
</html>