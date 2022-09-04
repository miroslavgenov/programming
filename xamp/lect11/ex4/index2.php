<?php 
require_once("index1.php");

foreach($vehicle as $v){
    $v->show();

    if(method_exists($v,"helloFromCar")){
        echo $v->helloFromCar();
        printf("%6.1f",$v->speed);
    }
    if(method_exists($v,"helloFromByke")){
        echo $v->helloFromByke();
        printf("%d",$v->speed);
    }
    
}


?>