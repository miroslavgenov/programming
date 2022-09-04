<?php 
    if(isset($_POST['person_name'])){
        echo $_POST['person_name'];
        $p_name=$_POST['person_name'];

        try{
            $conn = new PDO("mysql:host=localhost;dbname=first;charset=utf8", "root", "");
        $query=   $conn->prepare("INSERT into person(name) values (:name)");
        $query->bindParam(':name',$p_name);
        $query->execute();
        }catch(PDOException $e){
            echo "Error" . $e->getMessage();
        }
        
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <a href="show.php">Show Persons</a>
    <h1>Add to data base</h1>
    <form action="index.php" method="post">
        <label for="">Name <input type="text" name="person_name" id=""></label>
        <input type="submit" value="Submit">
    </form>
    <form action="show.php" method="get">
        <h1>Get Persons name</h1>
        <input type="submit" value="Show">
    </form>
</body>
</html>