<?php 

// echo "HELLO FROM PROGRAMLANGUAGE MODEL<br>";



class ProgLanguage{
    public static function getFirstNumberByRateLanguages($number){
        // example get first 5 languages by desc order
        // echo "public static function getFirstNumberByRateLanguages(number)<br>";
        // echo "$number hereeee!! <br>";
        
        $connect = DataBase::connectDataBase();
        #dont work
        // $query = "SELECT * FROM prog_language LIMIT :number";
        $query = "SELECT id,language,creator,dateCreated,Rate2021 FROM prog_language ORDER BY Rate2021 DESC LIMIT ".$number;
        $statement = $connect->prepare($query);
        #dont work
        // $statement->execute([":number"=>$number]);    
        $statement->execute();    
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        // print_r($result);
        return $result;
        
    }

    public static function getAllLanguagesAfterYear($year){
        // echo "public static function getAllLanguagesAfterYear(year)<br>";
        $connect = DataBase::connectDataBase();
        $query = "SELECT * FROM prog_language WHERE dateCreated>:year ORDER BY dateCreated ASC";
        $statement = $connect->prepare($query);
        $statement->execute([":year"=>$year]);
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        // print_r($result);
        return $result;
    }

    public static function getAllLanguages(){
        // echo "public static function showAllLanguages()<br>";
        $connect = DataBase::connectDataBase();
        $query = "SELECT * FROM prog_language";
        $statement = $connect->prepare($query);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;

    }

    public static function addToDataBase($params){
        // echo "public static function addToDataBase(params)<br>";
        // echo "<pre>";
        // print_r($params);
        // echo "</pre>";
        $connect = DataBase::connectDataBase();
        $query = "INSERT INTO prog_language (language, creator, dateCreated, Rate2021) VALUES (:language, :creator, :dateCreated, :Rate2021)";
        $statement = $connect->prepare($query);
        $arguments = [
                ":language"=>$params['language'],
                ":creator"=>$params['creator'],
                ":dateCreated"=>$params['dateCreated'],
                ":Rate2021"=>$params['Rate2021']
        ];
        $statement->execute($arguments);
        
        // DataBase::connectToDataBase();
    }
}






?>