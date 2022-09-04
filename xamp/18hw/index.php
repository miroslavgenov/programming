<?php



function showDir($currentDir){

    echo "<br>Dir of $currentDir<br>";
    if($handle = opendir($currentDir)){
        
        while(($item = readdir($handle) ) !== false){
            echo "$item<br>";
            if(is_dir($item) && $item !="." && $item !=".."){    
                    showDir($item);        
            }
        }
        closedir($handle);
        echo "<br>-------<br>end of $currentDir<br>---------<br>";
    }
}


showDir(getcwd())  ;

?>