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

class Controller{

    static function actionIndex(){
        echo "Hello static method<br>";
    }
}


//work
Controller::actionIndex();


?>
