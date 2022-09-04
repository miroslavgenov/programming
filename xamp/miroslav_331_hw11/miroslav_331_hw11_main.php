<?php 
require_once("miroslav_331_hw11_class.php");


$useStocks=array();

$connect = new PDO("mysql:host=localhost;dbname=miroslav_331_hw11_database;charset=utf8","root","");
$query = "SELECT * FROM storage";
$str=$connect->prepare($query);
$str->execute();
$readStocks = $str->fetchAll(PDO::FETCH_OBJ);

// echo "<pre>";
// print_r($readStocks);
// echo "</pre>";

// echo $readStocks[0]->price;

foreach($readStocks as $el){
    $useStocks[]= new $el->class_type($el);
}

function showTable($table){
    echo "<table>";
    echo "<tr>";
    echo "<td>id</td>";
    echo "<td>type</td>";
    echo "<td>name</td>";
    echo "<td>price</td>";
    echo "<td>expire_date</td>";
    echo "</tr>";
    
    foreach($table as $element){
        if(get_class($element)=="Food"){
            // 
            $strEleme = array();
            foreach($element as $el){
                $strEleme[]=$el;
            }
            
            echo "<tr>";
            for($i=1;$i<count($strEleme);$i++){
                echo "<td>".$strEleme[$i]."</td>";
            }
            echo "<td>".$strEleme[0]."</td>";
            
            echo "</tr>";
    
            
        }else if(get_class($element)=="Stock"){
            echo "<tr>";
            foreach($element as $el){
                    echo "<td>".$el."</td>";
                }
                echo "</tr>";
        }
        
    }

    echo "</table>";
}




showTable($useStocks);

echo "<br>CHANGE PRICE id 3<br>";
$useStocks[2]->changePrice("-%50");

showTable($useStocks);



foreach($useStocks as $el){
    echo "<br>".$el->get_type();
    if(method_exists($el,"changePrice")){
        echo "<br>if(method_exists(el,\"changePrice\"))<br>";
        echo $el->get_price()."-> ";
        $el->changePrice("+%10");
        echo $el->get_price(). "<br>";
    }
    if(method_exists($el,"dayLeft")){
        echo "if(method_exists(el,\"dayLeft\"))<br>";
        echo $el->dayLeft()."<br>";
    }
}
showTable($useStocks);

?>



<style>
    table{background-color:lightgreen;}
    td{background-color:white;}
</style>