<?php

class Vehicle{
    public $id;
    public $yearCr;
    public $speed;
    public $type;

    public function __construct($id,$type="Prevozno sredsvo",$speed,$yearCr){
        $this->id=$id;
        $this->yearCr=$yearCr;
        $this->speed=$speed;
        $this->type=$type;
    }
    
    public function getAge(){
        return Date('Y') - $this->yearCr;
    }
    
    public function show(){
        echo $this->type."<br>";
        echo $this->getAge()."<br>";
        echo $this->speed."<br>";
    }
    public function travelTime($distant){
        return $distant/$this->speed;
    }
}
class Car extends Vehicle{
    public $fuel;
    public function __construct($obj){
        parent::__construct($obj->id,"Кола",$obj->speed,$obj->year_created);
        $this->fuel=$obj->fuel;
    }
    public function helloFromCar(){
        echo "CAR HELLO<br>";
    }
}

class Bycicle extends Vehicle{
    public function __construct($obj){
        parent::__construct($obj->id,"Колело",$obj->speed,$obj->year_created);
    }

    public function helloFromByke(){
        echo "HELLO BIKE<br>";
    }
}
?>