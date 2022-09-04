<?php 
require_once(PATH."\\models\\prog_language.php");

// echo "HELLO FROM LANGUAGE CONTROLLER<br>";
    



class LanguageController{

    public static function actionInfoRate($param){
        // echo "public static function actionInfoRate(param)<br>";
        $languages= ProgLanguage::getFirstNumberByRateLanguages($param);
        // echo $param.'<br>';
       require_once(PATH."\\views\\show_number_lang_by_desc_rate.php"); 
    }

    public static function actionYear($param){
        // echo "public static function actionYear(param)<br>";
       $languages= ProgLanguage::getAllLanguagesAfterYear($param);
       require_once(PATH."\\views\\show_prog_lang_after_year.php");

    }

    public static function actionListAll(){
        // echo "public static function actionListAll()<br>";
        $languages = ProgLanguage::getAllLanguages();
        require_once(PATH."\\views\\show_all_prog_lang.php");
        
    }



    public static function actionAdd(){
        
        // echo "public static function actionAdd() <br>";
        
        if(count($_POST)>0){
            // echo "<pre>";
            // print_r($_POST);
            // echo "</pre>";
            

            ProgLanguage::addToDataBase($_POST);
            require_once(PATH."\\views\\add_success.php");
        }else{
            #In echo we have form and script
            // the script is simple if the value of the year is y>1900 && y<2155 then its try
            // because if is not in the database will write 0000
            // and the script check if its true , then will add to database
            // if not true then prevent default of the form
            
            

            echo "
            
            <form method='post'>
            <fieldset>
            <legend>Add Programing language
            </legend>
            <label>Language
            <input type'text' required='required' name='language'></label><br>
            <label>Creator
            <input type'text' required='required' name='creator'></label><br>
            <label>yearCreated
            <input type'text' required='required' name='dateCreated'></label><br>
            <label>Rate2021
            <input type'text' required='required' name='Rate2021'></label><br>

                <input type='submit' value='Add'>
                </fieldset>
                </form>
                <script language='javascript'>

                var form = document.getElementsByTagName('form')[0];
                var yC= document.getElementsByName('dateCreated')[0];
                var yearValue;
                yC.addEventListener(\"blur\",()=>{yearValue=parseInt(yC.value)});
                form.addEventListener(\"submit\",(e)=>{
                    if(yearValue>1900 && yearValue<2155){
                        yC.value = yearValue;
                    }
                    else{
                        yC['style']['background']='red';
                        yC['style']['color']='white';
                        yC.value='';
                        yC['placeholder']='year>1900 && year<2155';
                        e.preventDefault();
                    }
                })
                

                </script>";
        }

        
        
    }
}

?>