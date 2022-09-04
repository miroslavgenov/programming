<?php
include_once ROOT.'/models/users.php';

class UsersController{

	public function actionList(){
		$users=array();
		$users=Users::getUsers();
		// echo "<h1>Списък потребители<h1>";
		// echo "<pre>";
		// print_r($users);
		// echo "<pre>";
		require_once (ROOT.'/views/list_all.php');
		return true;
	}

	public function actionView($params){
		//list($id, $second, $third)=$params;
		
		//list($id)=$params;
		if(is_numeric ($params[0])){
				$id=$params[0];
		}
		else {
			$name=$params[0];
		}
     
        if(isset($id)){
        	$user=Users::getUserById($id);
      //   	echo "<h2>Преглед на  потребител $id </h2>";
      //        echo "<pre>";
		    // print_r($user);
		    // echo "<pre>";
		  require_once (ROOT.'/views/list_one.php');
		  return true;
        }
		 if(isset($name)){
        	$users=Users::getUsersByName($name);
    
		  require_once (ROOT.'/views/list_all.php');
		  return true;
        }
	}
   public function actionAdd(){
	if(count($_POST)>0){
          $name= $_POST['name'];
          $email= $_POST['email'];
		  Users::addUser( $name,$email );
	}
	else {
	 echo '<form  method="post">
	Име<br>
	<input type="text" name="name"><br>
    Еmail<br>
	<input type="text" name="email"><br>
	<input type="submit" value="Изпрати">
   </form>';

	}

}
}