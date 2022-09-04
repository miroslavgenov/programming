<?php 

class Stock
{
    public $id;
    public $type;
    public $name;
    public $price;

    public function __construct(
        $object,$type="Нехранителна стока"
    ){

        $this->id=intval($object->id);
        $this->name=$object->name;
        $this->price= doubleval( $object->price);
        $this->type=$type;

    }

    public function get_id(){return $this->id;}
    public function get_name(){return $this->name;}
    public function get_price(){return $this->price;}
    public function get_type(){return $this->type;}
    
    public function set_id($value){$this->id=$value;}
    public function set_name($value){$this->name=$value;}
    public function set_price($value){$this->price=$value;}
    public function set_type($value){$this->type=$value;}

    public function show(){
        echo $this->get_id()." ".$this->get_name()." ".$this->get_price()." ".$this->get_type();
    }

    // todo
    public function changePrice($percent){
        
        if($percent[0]=='-'){
            $percent = intval(substr($percent,2));
           $result = $this->price - ($this->price*($percent/100));
            $this->set_price($result);
        }elseif($percent[0]=='+')
        {
            $percent = intval(substr($percent,2));
           $result = $this->price + ($this->price*($percent/100));
            $this->set_price($result);
         }
        
        

    }

}




class Base{
    public $id;
    public $type;
    public $name;
    public $price;
    public $expire_date;
    public function __construct(
$id,
$name,
$price,
$type,
$expire_date
){

     $this->id= $id;
     $this->type=     $type;
     $this->name=     $name;
     $this->price=     $price;
    $this->expire_date=$expire_date;



    }

}


class Food extends Stock
{
    public $expire_date;

    public function __construct($object){
        parent::__construct($object,"Хранителна стока");
        $this->expire_date = $object->expire_date;

    }

    public function get_expire_date(){return $this->expire_date;}
    public function set_expire_date($value){$this->expire_date=$value;}
    

    public function show(){
        parent::show();
        echo " ".$this->get_expire_date();
    }


    public function dayLeft(){
        date_default_timezone_set('Europe/Sofia');
        $now = date("Y-m-d");

        $dateNow = new DateTime($now);
        $dateExp = new DateTime($this->expire_date);

        // echo date_format($dateNow,"y-m-d")."<br>";
        // echo date_format($dateExp,"y-m-d")."<br>";
        
        $interval  =  $dateNow->diff($dateExp);
        echo $interval->format('%a дни');
        
        
    }

    public function dayLeft1(){
        // my variant but show how much year , month and dates;

        $dt = date("Y-m-d");
        $dt=explode('-',$dt);
        $this->expire_date = explode('-',$this->expire_date);
        
        $daysleft = array();
        
        for($i=0;$i<count($this->expire_date);$i++){
            $this->expire_date[$i]=intval($this->expire_date[$i]);
            $dt[$i]=intval($dt[$i]);
            $daysleft[]=  $this->expire_date[$i]- $dt[$i];
        }        

            echo "Оставант Години: $daysleft[0] Месеца: $daysleft[1] Дни: $daysleft[2] <br>";
        
    }


}


// $b = new Base(1,"Lamp",100,"Food","2022-12-31");
// $f1=new $b->type($b);
// // echo "<pre>";
// // print_r($f1);
// // $f1->show();
// $f1->dayLeft();
// // echo "</pre>";






?>