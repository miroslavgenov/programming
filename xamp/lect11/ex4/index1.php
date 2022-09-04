<?php 

require_once("vehicle.php");

try{

    $connect = new PDO ("mysql:host=localhost;dbname=lect11_ex4","root","");
    $query = "SELECT * FROM vehicle";
    $str = $connect->prepare($query);
    $str->execute();
    // prevrushta go v stdClass Object // ne asociativen masiv kato FETCH_ASSOC
    // and we in the db there is attribute 'type'
    // Car , Vehicle and now we can make with this new result[0]->type will make Car or Bycicle
    $result = $str->fetchAll(PDO::FETCH_OBJ);
    // echo "<pre>";
    // print_r($result);
    // echo "</pre>";

    $vehicle =array();

    foreach($result as $res){
        // this will make Car or Vehicle
        // and $res is the obj who contains
        // ->id , yearCre , speed , etc
        //$res->type($res)
        $vehicle[] = new $res->type($res);
    }

    // echo "<pre>";
    // print_r($vehicle);
    // echo "</pre>";

}catch(PDOException $e){
    echo $e->getMessage();
}



?>