<?php  

// sample for faculty number but in utf-8
// СИ 11 , КСТ 13 

$pattern = "~([А-Я]+) (\d+)~";
echo "preg_match($pattern,СИ 33)<br>";
// return 1/0
echo preg_match($pattern,"СИ 33");

// for the replacement the regExp must be in groups
echo "preg_replace(\$pattern,\$new_template,\$string)<br>";
echo "<br>preg_replace(~([А-Я]+) (\d+)~,FacultyNumber: $2 \n Speciality: $1 ,СИ 331)<br>";

// return the replacement
// if the patern if not tru then return the current string
echo preg_replace("~([А-Я]+) (\d+)~","FacultyNumber: $2 \n Speciality: $1 ","СИ 31")."<br>";

// 
echo "<br>The String doesnt match the pattern<br>";
echo preg_replace("~([А-Я]+) (\d+)~","FacultyNumber: $2 \n Speciality: $1 ","СИ31");



?>

