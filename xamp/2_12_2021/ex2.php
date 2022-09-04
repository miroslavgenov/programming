<?php 
class Person{
    function __construct(){
        echo "constructor<br>";
    }
function __destruct(){
    echo "destruct<br>";
}
private $FullName;
private $EGN;
private $phone;
private $address;

function SetData($n,$e,$p,$a){
    $this->FullName=$n;
    $this->EGN=$e;
    $this->phone=$p;
    $this->address=$a;
}
function GetFullName(){return $this->FullName;}
}

class Student extends Person{
    private $speciality;
    function SetSpeciality($s){
        $this->speciality=$s;
        function Out(){
            echo "$this->FullName , $this->speciality<br>";
        }
    }
}

$p1=new Person();

?>