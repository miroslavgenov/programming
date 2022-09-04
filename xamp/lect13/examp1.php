<?php  

class NewsController{

    public static function actionIndex(){
        echo "NewsController -> actionINdex()<br>";
    }
    public static function actionList(){
        echo "NewsController -> actionList()<br>";
    }

    // public function actionView($params){
    //     //receive the params as array
    //     echo "<i>";
    //     echo "NewsConstroller -> actionView(\$params)<br>";
    //     echo "<pre>";
    //     print_r($params);
    //     echo "</pre>";
    //     echo "</i>";
    // }

    // call_user_func_array(Array($controllerObj,$actionName),$params);
    // call_user_function_array if i use this need to use this function 
    public function actionView($secion , $id){
    // receiving the paramt with specific names    
        echo "NewsConstroller -> actionView(\$section,\$id)<br>";        
    
    }

}

class StoriesController{
    public function actionIndex(){
        echo "StoriesController -> actionIndex()<br>";
    }
}




// asociative array  $pattern -> $template
$routes = [
    "/lect13/examp1.php/([a-z]+)/(\d+)"=>"news/view/$1/$2",
    "/lect13/examp1.php/news"=>"news/index",
    "/lect13/examp1.php/stories"=>"stories/index",
    "/lect13/examp1.php/list"=>"news/list"

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

            // this will test fo
            // news/movies/32323

            echo "New address is: ".preg_replace("~$pattern~",$template,$uri);
            $newUri=preg_replace("~$pattern~",$template,$uri);
            $newParts = explode("/",$newUri);
            
            $controllerName = ucfirst(array_shift($newParts))."Controller";
            $actionName = "action".ucfirst(array_shift($newParts));
            echo "<br> $controllerName $actionName <br>";
            
            echo "Parameters<br>";
            echo "<pre>";
            print_r($newParts);
            echo "</pre>";
            
            $params=NULL;
            if(count($newParts)==2){
                $params = $newParts;
            }

            $controllerObj = new $controllerName();
            // sending parameters as array
            // $controllerObj->$actionName($params);

            //sending params with singil params as named in the function
            call_user_func_array(Array($controllerObj,$actionName),$params);



        }else{
            echo "<br>Correct but there is not additional parameters<br>";
        }
        
        break;
    }else{
        echo "<br> There is no match with: <br><b>\$uri =</b> $uri and the <b>\$pattern</b>: $pattern <br>";
    }

}


// print_r($_SERVER['REQUEST_URI']);
// echo "</pre>";





?>

