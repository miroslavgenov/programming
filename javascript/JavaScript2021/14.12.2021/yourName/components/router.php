<?php

class Router {
	private $routes;

	public function __construct(){
		//път към файла с марщрутите
		$routesPath= ROOT.'/config/routes.php';
		$this->routes=include($routesPath);
		echo "<br>Маршрути<br>";
		echo "<pre>";
		print_r($this->routes);
		echo "</pre>";
	}
    
    // низ на заявката (request string)
    private function getURI(){
    	$uri="";
    	if(!empty($_SERVER['REQUEST_URI'])){
			$uri=  trim($_SERVER['REQUEST_URI'],'/');
			echo 'получен адрес в getURI():$uri='.$uri."<br>";
		}
	
		return urldecode($uri);
		
    }
	public function run(){
      	 //Заявка
		$uri= $this->getURI();
		echo 'Метод run() $uri='.$uri."<br>";
     
         //търсим заявката в $routes;
		foreach ($this->routes as $urlPattern=>$path){
			echo "<br>Търсен адрес $uri<br>";
			echo "Търсим съвпадение с шаблона:  $urlPattern<br>";
			echo "При съвпадение ще се обработва от (клас/метод): $path<br>";


			if(preg_match("~$urlPattern~", $uri)){
				echo "***Намерено е съвпадение за адреса!***<br/>"; 
				$parts= explode('/', $path );
				echo 'Съставки на маршрута:контролер метод [параметри]<br>';
				echo "<pre>";
		           print_r($parts);
		        echo "</pre>";
				$count=count($parts);
				
				if($count>2){ //адресът съдържа параметри, които следва да се извлекат по шаблона
					$route= preg_replace("~$urlPattern~", $path, $uri);
					echo   "PATH: $path<br>";
					echo   "ROUTE: $route<br>";
					$parts= explode('/', $route );
					echo 'Съставки на маршрута след preg_replace<br>';
				    echo "<pre>";
		             print_r($parts);
		            echo "</pre>";
				$count=count($parts);
				}
				
                        
		       	//Генерираме имената на контролера и метода за действие		
				
			//	$controllerName=ucfirst($parts[0]."Controller");
				$controllerName=ucfirst(array_shift($parts)."Controller");
				echo "<br>Клас: $controllerName<br/>";
                 
				$actionName="action".ucfirst(array_shift($parts));
                echo "Метод: $actionName<br/><br>";

          
                if($count>2){
                	 $parameters=$parts;
                echo "Параметри на $actionName<br/>";	 
                echo"<pre>";
                  print_r( $parameters);               
                 echo"</pre>";
                }
                else{
                	 $parameters=null;
                }
               

                //файл на контролера
				$controllerFile=ROOT."/controllers/".$controllerName.".php";
		        if(file_exists($controllerFile)){
		         	echo "<br/>Файлът на контролера е намерен<br/>";
		        	include_once($controllerFile);
		        }

		        //Създаваме обект от класа на контролера
		        $controllerObj= new $controllerName();
				// извикваме метода му за действие
				$result= $controllerObj->$actionName($parameters);
               
				break;

			}  //  край на if(preg_match(...)
		}// край на foreach за обхождане на маршрутите
	}// край на run()
}

