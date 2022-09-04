<!DOCTYPE html>
<html>
<head>
    <title>Потребители</title>
    <style>
     .single_record{
         page-break-after: always;
     } 
    </style>
</head>
<body class= 'single_record'>
    <ul>
      <?php foreach($user as $prop): ?>
         <li><?=$prop?></li>
       <?php endforeach; ?>  
    </ul>

</body>
</html>


 
 
