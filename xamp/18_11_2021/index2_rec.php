<?PHP

function ShowFolder($p){
    $h = opendir($p); // open the folder as file
    // if this is succssesfull
    if($h){
        // yes
        // now will processing the content in the folder
    
        while(($item = readdir($h)) !== false){
            // why !== false , because if the
            // name of the folder is 0 
            // this will convert the name to false
            // and will stop the while 
            // but if !== will check the name typeof and the value
            echo "$item<br>";
        }
        closedir($h);
        echo "-----------<br> end of $p <br>---------<br>";
    }else{echo "error<br>";}
    echo "<h3>directory of $p</h3>";
}//ShowFolder

ShowFolder(getcwd());
?>