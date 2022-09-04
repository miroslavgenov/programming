<?php 

$my_arr=[
    'food'=>'pizza',
    'beverage' => 'water',
    'price'=>2,
    '3'=>[
        1,2,3 , '3.1'=> [5,6,7],
        '3.2'=>[-55,'3.3'=>[8,9,10],11,12,13]
    ],
    'store'=>[
        'sweets'=>['cookey'=>['chocolate'=>['gram'=>[50,100,40],7,8]]],
        'vegetable' => ['fries'=>[4,2,7]]
    ]

    ];

function ShowArray($array){
    foreach($array as $index => $element){
        if(!is_array($element)){
            echo "$index -> $element<br>";
        }//if
        else{
            echo "<br> index ->$index  inner Array:<br>";
            ShowArray($element);
            echo "<br> $index end<br>";
        }//else
    }//foreach

}//ShowArray

ShowArray($my_arr);

?>