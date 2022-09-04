<!DOCTYPE html>
<html>
<head>
    <title>Списък потребители</title>
     <style>
    table, td, th{
        border:1px solid red;
        border-collapse: collapse;
        padding: 5px;
    }

 </style>
</head>
<body>
   <table style="page-break-before: always" >
  <tr>
    <th>Номер</th>
    <th>Име</th>

    <th>Имейл</th>
  </tr>
  <?php for($i=0, $count=count($users); $i<$count; $i++): ?>
  <tr>
    <td><?=$i?></td>
    <td><?=$users[$i]['name']?></td>
    <td><?=$users[$i]['email']?></td>
  </tr>
  <?php endfor;?>
 
</table>

</body>
</html>


 
 
