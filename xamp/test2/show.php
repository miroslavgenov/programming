<?php
    try{
        $conn = new PDO("mysql:host=localhost;dbname=first;charset=utf8", "root", "");
        $query=   $conn->prepare("select * from person;");
        $query->execute();
        $result=$query->fetchAll(PDO::FETCH_ASSOC);
        
        for($i=0;$i<count($result);$i++){
            foreach ($result[$i] as $key => $value) 
                if($key=="name") echo  $value . "</br>" ;
            
        }
        
    }catch(PDOException $e){
        echo "Error" . $e->getMessage();
    }
?>