<?php 

class Router{
    
    private $routes;

    public function __construct(){
        $this->routes = require_once(PATH."\\configs\\routes.php");
        // echo "<pre>";
        // print_r($this->routes);
        // echo "</pre>";

        // echo "<br>Components Router constructor <br>";

    }

    private function getUri(){
        // echo "function getUri()<br>";
        // echo "<pre>";
        // print_r($_SERVER);
        // echo "</pre>";
        $uri = $_SERVER ['REQUEST_URI'];
        $uri = trim($uri,'/');
        // echo $uri;
        // echo $_SERVER['REQUESTED_URI'];
        return urldecode($uri);
        }


    public  function run(){
        // echo "<br>public  function run()<br>";
        // echo $this->getUri();
        $uri = $this->getUri();
        
        // echo "<pre>";
        // print_r($_SERVER);
        // echo "</pre>";
        
        // echo "Components Router -> run() <br>";
        // echo "$uri <br>";

        // walk trought routes where we have
        // patternt and template , the template we use to 
        // call the controllerClass and call the actionName method

        foreach($this->routes as $pattern=>$template){
            
            if(preg_match("~$pattern~",$uri)){
                // echo "URI Match<br>";
                $newRoute = preg_replace("~$pattern~",$template,$uri);
                // echo "$newRoute <br>";
                // get the uri splited by '/'
                // to count if have parameters
                // if the template have 3 string after split
                // we have parameters
                $newRouteParts = explode('/',$newRoute);

                // echo "NewRoutParts : ". count($newRouteParts). "<br>";

                $controllerName=NULL;
                $actionName=NULL;
                
                if(count($newRouteParts)==3){
                    // echo "count(newRouteParts)==3<br>";
                    $controllerName = ucfirst(array_shift($newRouteParts))."Controller";
                    $actionName = "action".ucfirst(array_shift($newRouteParts));
                    $param = $newRouteParts[0];

                    // check if the user enter year/(\d)
                    if($actionName==='actionYear'){
                        #todo
                        // echo "if(actionName==='actionYear')<br>";
                        // check if the digit after year is number
                        // and if >1900 && <2155
                        if(intval($param)){
                            // echo "if(inval(param))<br>";
                            $param =intval($param);
                            if($param>1900 && $param<2155){
                                // echo "if(param>1900 && param<2155)<br>";
                                require_once(PATH.'\\controllers\\'.$controllerName.'.php');
                                $controllerObj = new $controllerName();
                                $controllerObj->$actionName($param);

                            }else{
                                echo "<h1>Не валидна дата $param </h1>";
                                echo "<p><u>Датата трябва да бъде <b>>1900 и <2155</b></u></p>";
                            }
                        }
                        // if user enter inforrate\(\d)
                    }else if ($actionName==='actionInfoRate'){
                        #todo
                        // echo "(actionName==='actionInfoRate')<br>";
                        if(intval($param)){
                            // echo "if(inval(param))<br>";
                            $param =intval($param);
                                require_once(PATH.'\\controllers\\'.$controllerName.'.php');
                                $controllerObj = new $controllerName();
                                $controllerObj->$actionName($param);

                            
                        }
                    }

                    // require_once(PATH.'\\controllers\\'.$controllerName.'.php');
                    // echo "$controllerName !!! $actionName <br>";
                    // $controllerObj = new $controllerName();
                    
                    
                    #todo !!!
                }else if(count($newRouteParts)==2){
                    // echo "count(newRouteParts)==2<br>";
                    $controllerName = ucfirst(array_shift($newRouteParts))."Controller";
                    $actionName = "action".ucfirst(array_shift($newRouteParts));
                    // echo "$controllerName !!! $actionName <br>";
                    
                    require_once(PATH.'\\controllers\\'.$controllerName.'.php');
                    $controllerObj = new $controllerName();
                    $controllerObj->$actionName();
                    
                }

                break;
            }
        }
        
    }
}


/*
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("JAVASCRIPT","Brendan Eich","1995",2.30);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("C++","Bjarne Stroustrup","1985",7.73);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("PYTHON","Guido van Rossum","1991",12.90);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("C","Dennis Ritchie","1972",11.80);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("SQL","ISO/IEC","1974",1.79);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("KOTLIN","JetBrains","2010",0.57);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("JAVA","James Gosling","1996",10.12);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("ASSEMBLY","David Wheeler","1940",2.25);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("C#","Anders Hejlsberg","2000",6.40);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("POWERSHELL","Microsoft","2006",0.22);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("ACTIONSCRIPT","Gary Grossman","1998",0.16);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("LUA","Roberto Ierusalimschy","1993",0.40);
INSERT INTO `prog_language`(`language`, `creator`, `dateCreated`, `Rate2021`) VALUES ("BASH","Brian Fox","1989",0.15);
*/




?>