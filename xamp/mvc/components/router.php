<?php

class ComponentRouter{
        private $routes;
        
        public function __construct(){
            $this->routes = config_route();
        }
        
        public function show(){
            echo "<pre>";
            print_r($this->routes);
            echo "</pre>";
        }
        
        private function gerUri(){
            $uri="";
            if(!empty($_SERVER['REQUEST_URI'])){
                //echo $_SERVER['REQUEST_URI'];
                $uri = trim($_SERVER['REQUEST_URI'],'/');
                //echo "<br>".$uri."<br>";
                //echo urldecode($uri);
            }
            return urldecode($uri);
        }
        
        public function run(){
            $uri = $this->gerUri();
            echo $uri;
            
            foreach($this->routes as $pattern=>$template){
                echo "<br>$pattern $template<br>";
                if(preg_match("~$pattern~",$uri)){
                    echo "!!!";
                    
                    if(count(explode('/',$uri))>2){
                        $newRoute=preg_replace("~$pattern~",$template,$uri);
                        //echo $newRoute;
                        $newParts = explode('/',$newRoute);
                        //print_r($newParts);
                    }
                    
                    $controllerName = ucfirst(array_shift($newParts))."Controller";
                    echo $controllerName;
                    $actionName="action".ucfirst( array_shift($newParts) );
                    echo $actionName;
                    
                    $params=NULL;
                    if(count($newParts)>0){
                        $params=$newParts;
                    }
                    
                    // check if the file of the controller exists
                    //$controllerFile = ...
                    //if(file_exists($controllerFile)){
                      //  include_once($controlerFile);
                    //}
                    
                    $controllerObj = new $controllerName();
                    $result = $controllerObj->$actionName($params);
                    
                    break;
                }
            }
        }
        
}

?>