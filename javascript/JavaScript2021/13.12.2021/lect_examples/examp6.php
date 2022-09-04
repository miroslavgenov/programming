<?php  


// to analise the address from the url
// and to call the needed method from the request
// knowing the address
//

/*

First we need to know the class and then 
the function

This class is called NameController
and the methods are actionName



*/

/*Analise the adrres 

then to identified class Controller and then 
identified the method

*/

class NewsController{

    public static function actionIndex(){
        echo "NewsController -> actionINdex()<br>";
    }
    public static function actionList(){
        echo "NewsController -> actionList()<br>";
    }

    public function actionView($params){
        //receive the params as array
        echo "NewsConstroller -> actionView(\$params)<br>";
        echo "<pre>";
        print_r($params);
        echo "</pre>";
    }

    // public function actionView($secion , $id){
    // // receiving the paramt with specific names    
    //     echo "NewsConstroller -> actionView(\$section,\$id)<br>";        
    
    // }

}

class StoriesController{
    public function actionIndex(){
        echo "StoriesController -> actionIndex()<br>";
    }
}


?>
