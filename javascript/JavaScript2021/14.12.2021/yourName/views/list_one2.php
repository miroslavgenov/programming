<?php

echo "
<div class= 'single_record'>
    <ul>
      <?php foreach($user as $prop): ?>
         <li><?=$prop?></li>
       <?php endforeach; ?>  
    </ul>

</div>";
?>

  <style>
     .single_record{
         page-break-after: always;
     } 
    </style>


 
 
