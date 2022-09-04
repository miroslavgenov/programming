<?php

// scan dir

$files = scandir("pages");
echo "<pre>";
print_r($files);
echo "</pre>";

foreach($files as $el){
    // echo $el."<br>";
    if(is_file('pages/'.$el)){
        echo "<br>";
        echo "<a href=\"index3.php?file=$el\">T$el</a>";
    }
}
?>


