<?php  

$list = [
    "SI 12",
    "KST 331",
    "SI 44",
    "S66", # dont mathc
    "Si 334", # dont match 
    "Sя 33" # dont match 
];

$pattern="~([A-Z]+) (\d+)~";
$template="Spec: $1 NM: $2";

foreach($list as $el){
    echo preg_replace($pattern,$template,$el)."<br>";
}

?>