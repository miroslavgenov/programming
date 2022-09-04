<?php 
 
class Person
{
	//niva na dostup
	// publick
	// $FullName;
	// $phone;
	// $EGN;
	// $address;
	// private
	private $FullName;
	private $phone;
	private $EGN;
	private $address;
	//protected
	
	//
	function SetData($n,$e,$p,$a){
		$this->FullName=$n;
		$this->EGN=$e;
		$this->phone=$p;
		$this->address=$a;
	}

	// методи които трябва да не излизат
	// извън класът трябва да са привате

	function GetFullName(){
		return $this->FullName;
	}

	function show(){
		echo $this->getName();
	}
	private function getName(){return $this->FullName;}

}

$p1=new Person();
$p1->SetData("Peter",'9988123','0879123','Burgas');
echo $p1->GetFullName().'<br>';
$p1->show();


?>