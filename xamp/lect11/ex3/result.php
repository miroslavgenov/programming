<?php
session_start();
echo "<pre>";
var_dump($_SESSION);
echo "</pre>";
echo "<pre>";
var_dump($_POST);
echo "</pre>";

// show the name of the file where the session is 
// save in xamp tmp
echo session_id();
//C:\xampp\tmp




?>