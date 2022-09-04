<?php

class Users {
	
	public static function getUsers(){
		$db= Database::getConnection();
		$query="SELECT name, email FROM data";
		$statement= $db->prepare($query);
		$statement->execute();

		$users= $statement->fetchAll(PDO::FETCH_ASSOC);
        return $users;
	}
	
	public static function getUsersByName($name){
		$db= Database::getConnection();
		$stmt= $db->prepare("SELECT * FROM data  WHERE  name=:name");
		$stmt->execute([':name'=>$name]);

		$users= $stmt->fetchAll(PDO::FETCH_ASSOC);
        return $users;
	}

	public static function getUserById($id){
		$id= intval($id);
		if($id){
		$db= Database::getConnection();
		$stmt= $db->prepare("SELECT * FROM data  WHERE  id=:id");
		$stmt->execute([':id'=>$id]);

		$user= $stmt->fetch(PDO::FETCH_ASSOC);
        return $user;

		}
	}

	public static function addUser($name,$email){
		$db= Database::getConnection();
		$stmt= $db->prepare("INSERT INTO  data (name, email)  values (:name, :email)");
		$stmt->execute([':name'=>$name, ':email'=>$email,]);
    }
}