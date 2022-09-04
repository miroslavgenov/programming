<?PHP
// to return more then one parameter we use referention

//php function

function fm($v1 , $v2){
    return ($v1 < $v2) ? $v1:$v2;
}

echo fm(1,2).'<br>';


function fmei($a,$me,$ime){
    
  $IsFirst = true;
  // $k is index $v is value
  foreach($a as $k => $v){
    if($IsFirst){
        $me = $v;
        $ime = $k;
        $IsFirst = false;
    }else{
        if($IsFirst){
            $me=$v;
            $ime=$k;
            $IsFirst = false;
        }else{
            if($v <$me){
                $me = $v;
                $ime = $k;
            }
        }
    }
  }

}

function fmei1($a,&$me,&$ime){
    
  $IsFirst = true;
  // $k is index $v is value
  foreach($a as $k => $v){
    if($IsFirst){
        $me = $v;
        $ime = $k;
        $IsFirst = false;
    }else{
        if($IsFirst){
            $me=$v;
            $ime=$k;
            $IsFirst = false;
        }else{
            if($v <$me){
                $me = $v;
                $ime = $k;
            }
        }
    }
  }

}



$ar[0] = 5;
$ar[3] = 11;
$ar['r'] = 101;



// in php there is no pointer put have referentions
fmei($ar, $e, $i);


echo "min: $i --> $e<br>";
fmei1($ar , $e1 , $i1);
echo "!min $i1 --> $1<br>";





?> 