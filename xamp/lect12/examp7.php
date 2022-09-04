<?php  

// asociative array  $pattern -> $template
$routes = [
    "/lect12/examp7.php/([a-z]+)/(\d+)"=>"news/view/$1/$2",
    "/lect12/examp7.php/news"=>"news/list",
    "/lect12/examp7.php/stories"=>"news/index"
];


// this is the url that i enter in the 
// browser address
$uri = $_SERVER['REQUEST_URI'];
// echo $uri;
echo "REQUST_URI: is:  $uri <br>";
echo "<pre>";
print_r($routes);
echo "</pre>";

foreach($routes as $pattern =>$template){

    if(preg_match("~$pattern~",$uri)){
        
        echo "<br><b>Correct</b>";
        echo "<br><b>\$uri</b>= $uri  = <b>\$pattern</b>= $pattern <br>";
        
        echo "<br>Sustavki na adresa<br>";
        $partsuri = explode("/",$uri);
        array_shift($partsuri);

        $partstemp = explode("/",$template);
        
        echo "<pre>";
        print_r($partsuri);
        echo "</pre>";
        echo "<pre>";
        print_r($partstemp);
        echo "</pre>";
        
        
        $count = count($partstemp);
        if($count>2){
            echo "New address is: ".preg_replace("~$pattern~",$template,$uri);

        }
        
        break;
    }else{
        echo "<br> There is no match with: <br><b>\$uri =</b> $uri and the <b>\$pattern</b>: $pattern <br>";
    }

}


// print_r($_SERVER['REQUEST_URI']);
// echo "</pre>";





?>
