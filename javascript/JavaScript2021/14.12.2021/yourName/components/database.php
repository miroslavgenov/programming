<?php 

class Database {
	public static function getConnection(){
		$dbParsPath=ROOT.'/config/db_params.php';
		$params= include($dbParsPath);
	  //   var_dump($params);
		$dbInfo="mysql:host={$params['host']};dbname={$params['dbname']};charset=utf8";
		return new PDO($dbInfo, $params['user'], $params['password']);
	}	
	
}