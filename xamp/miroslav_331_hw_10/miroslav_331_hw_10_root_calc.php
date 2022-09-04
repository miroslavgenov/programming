<?php  

function calculate($num){
// print_r($num);
// дискриминанта
$b=$num[1];
$bSq=$num[1]*$num[1];
// echo $bSq;
$sec= 4*$num[0]*$num[2];

$disk=$bSq-$sec;
// echo $disk;
$res=array();
$x1;
$x2;

if($disk>0){
    // have two корени
    array_push($res, intval((-$b +$disk)/2*$num[0]));
    array_push($res, intval((-$b -$disk)/2*$num[0]));

    return $res;
}
elseif($disk===0){
    $res = -$b/(2*$num[0]);
    return $res;
// echo "===";
}elseif($disk<0){
    // dont have корен
    // echo "<";
    return FALSE;
}


}
function getOnlyNumber($arr){
    $myArr=array('','','');
    $increment=0;
    // print_r($arr);
    foreach($arr as $idx=>$el){
        if($idx===0){
            // if -2
            if(is_int(intval($el))===FALSE){
                $myArr[$increment]=$myArr[$increment].$el;
                // print_r($myArr);
            }else{
                $myArr[$increment]=$myArr[$increment].$el;
                // print_r($myArr);
            }
        }elseif($idx>0){
            if($el==='-' || $el==='+'){
                $increment++;
                $myArr[$increment]=$myArr[$increment].$el;
                // print_r($myArr);
                continue;
            }
            if($el==='='){
                break;
            }
            $myArr[$increment]=$myArr[$increment].$el;
        }
        
    }
    
    $resusltInt=array();
    // push value as int
    foreach($myArr as $el){
        array_push($resusltInt,intval($el));
    }
    
    return $resusltInt;
}



    

function convertToCalculate($array,&$a,&$b,&$c){
    
    foreach($array as $i => $el){
        if(el===0){return FALSE;}
elseif(i===0){$a=intval(el);}
elseif(i===1){$b=intval(el);}
elseif(i===2){$c=intval(el);}
    }
return TRUE;
    
    
}

function squareEquation($solve){
    $len = strlen($solve);
    $values=NULL;
    $values=array();
    

    if($solve[$len-1]=='0'){
            $j=0;
            // get !=x && !=^2 
        for($i=0;$i<$len;$i++){
            if($i==0 && $solve[$i]=='x'){
                array_push($values,1);
            }
            if($solve[$i]!='x' && ($solve[$i]!='^' && $solve[$i-1]!='^')){                
                    array_push($values,$solve[$i]);
            }
        }
        // get only the number without +
        // print_r($values);
        $values=getOnlyNumber($values);
        // print_r($values);
       $reslut = calculate($values);
       if($reslut===FALSE){
        // no roots   
        return FALSE;
       }else{
          if(is_array($reslut)===TRUE){
              // two roots
            return $reslut;
          }
          // onle one root
          return $reslut;
       }
    //    print_r($reslut);
        



    }
    else{
        // echo "Not equation =0";
        return FALSE;
    }
        
    }




// squareEquation("x^2-5x+6=0");

?>