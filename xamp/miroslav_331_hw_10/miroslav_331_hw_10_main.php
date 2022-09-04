<?php 
$res="";
    require_once("miroslav_331_hw_10_root_calc.php");
    if(isset($_POST['solve'])){
        
        $res= squareEquation($_POST['solve']);
        if(is_array($res)){
            $res= $res[0].','.$res[1];
        }elseif($res===FALSE){
            $res="No result";
        }
    }
    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Root</title>
</head>
<body>
    <form action="miroslav_331_hw_10_main.php" method="post">
        <h1>Решаване на пълно квадратно уравнение</h1>
        <p>Example: 2x^2-5x+6=0</p>
        <input type="text" name="solve" id="" value="">
        <input type="reset" name="" id="">
        <input type="submit" value="Calculate">
        <br>Result
        <input type="text" name="" id="" value="<?=$res?>" disabled>
        
    </form>
</body>
</html>