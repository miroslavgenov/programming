<?PHP

$a[0]=1;
$a[1]=2;
$a['q']=3;
$b[0] = 'z';
$b[3]='y';
$a[4] = $b;
$b[5] = '1';

//echo $a[4][0].'<br>';
foreach($a as $v)
echo "$v<br>";
foreach($a as $i => $e)
echo "<p>$i --> $e </p>";
?>