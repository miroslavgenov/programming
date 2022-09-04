<?php 
class Person{
    private $Name;
    private $Age;

    function __construct(){
        
    }

    function GetAge(){return $this->Age;}

    function GetName(){
        return $this->Name;
    }
    function SetAge($a){$this->Age=$a;}
    function SetName($n){
        $this->Name = $n;
    }
}


$p1=new Person();
$p1->SetAge(10);
$p1->SetName("Alex");
echo $p1->GetName()."\n";
echo $p1->GetAge()."\n";


?>