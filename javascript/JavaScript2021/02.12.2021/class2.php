<?php 
class Person{
    private $Name;
    private $Age;

    function __construct($n,$a){
        $this->SetNameAge($n,$a);
    }
    private function SetNameAge($n,$a){
        $this->Name=$n;
        $this->Age=$a;
    }

    function show(){
        echo "$this->Name , $this->Age";
    }
}

class Student extends Person{
    private $Spec;
    function __construct($n,$a,$s){
        parent::__construct($n,$a);
        $this->Spec=$s;
    }


    function show(){
        parent::show();
        echo " ,".$this->Spec."\n";
    }
    

}


$s1= new Student("ivan",10,"x");
$s1->show();


?>