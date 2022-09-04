<?php 

// options for errors
ini_set('display_errors',1);
error_reporting(E_ALL);

// path
define('PATH',dirname(__FILE__));

// the primary runing components
// is the component/route - check and the pattern 
// and the component/database -get the connection


function config_db(){

    return Array(
        "host"=>"localhost",
        "dbname"=>"users",
        "user"=> "root",
        "password"=>""
    );
}

function config_route(){
    // patterb => template 
    return array(
        "mvc/users/([0-9]+)"=>"users/view/$1",
        "mvc/users/([а-яА-Я]+)"=>"users/view/$1",
        "mvc/users/add"=>"users/add",
        "mvc/users"=>"users/list",
        "mvc/add"=>"users/add"
        "mvc/admins"=>"admin/index"

    );
}

class ComponentDatabase{
    public static function getConnection(){
        // $dbParsePath=
        $params = config_db();
        $dbInfo = "mysql:host={$params['host']};dbname={$params['dbname']}";
        echo "hello no error<br>";
        return new PDO($dbInfo,$params['user'],$params['password']);
    }
}

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
                    $controllerObj = new $controllerName();
                        $params=$newParts;
                        $result = $controllerObj->$actionName($params);
                    }
                    
                    
                    // check if the file of the controller exists
                    //$controllerFile = ...
                    //if(file_exists($controllerFile)){
                      //  include_once($controlerFile);
                    //}
                    break;
                    
                }
            }
        }
        
}

class UsersController{
    public function actionView($params){
        echo "Hello world!!";
        // here need to use the view where is the new php 
        // containing html file and looping or showing only 
        // the receivd data from the model
        $users= ModelUsers::get_userID($params);
        
        
        echo PATH;
        
        ?>
        <!-- this thinkg need to be in separate view php file -->
        <!-- example list_view_user_id -->
        <html>
        <head></head>
        <body>
        <?php for($i=0;$i<count(array(1,2,3));$i++): ?>
        <p><?=$i?></p>
        <?php endfor; ?>
        </body>
        </html>
        <!--end-->
        <?php
        return true;
    }
    public function actionList(){
       $users= ModelUsers::get_users();
    }
}

class ModelUsers{
    public static function get_users(){
        $connect = ComponentDatabase::getConnection();
        $query = "SELECT * FROM data";
        $statement = $connect->prepare($query);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        
        echo "<pre>";
        print_r($result);
        echo "</pre>";
        //return $result;
    }
    public static function get_userID($id){
        $connect = ComponentDatabase::getConnection();
        $query = "SELECT id,name FROM data WHERE id=:id";
        $statement = $connect->prepare($query);
        $statement->bindParam(":id",$id[0]);
        $statement->execute();
        $result = $statement->fetch(PDO::FETCH_ASSOC);
        return $result;
        //print_r($result);
    }
}


$router = new ComponentRouter();
$router->show();
$router->run();




// echo "<pre>";
// print_r(route_config());
// echo "</pre>";

// echo "<pre>";
// print_r($_SERVER);
// echo "</pre>";

// echo "<br>".$_SERVER['REQUEST_URI']."<br>";

// echo getcwd();

// echo __FILE__;
?>