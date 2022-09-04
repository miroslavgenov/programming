<?php 
// data base usage
    if(count($_POST)>0){
        $name=$_POST['name'];
        $email=$_POST['email'];


        //var1
        // $connect = new PDO("mysql:host=localhost;dbname=lect11_ex2;charset=utf8","root","");
        // // // zadavane na kodirovka
        // //$connect->exec("set names utf8");
        // // // v prepare se izbqgvat sql injections i se zapisva zaqwvkata
        // $query = $connect->prepare("INSERT INTO data (name,email) VALUES (:name,:email)");

        // // //alternativen method na bindParam
        // $args=['name'=>$name,'email'=>$email];
        // $query->execute($args);

        // var2
        $connect = new PDO("mysql:host=localhost; dbname=lect11_ex2;charset=utf8",'root','');
        // $connect->exec("SET NAMES UTF8");
        $query = "INSERT INTO data(name,email) VALUES(:name,:email)";
        $str = $connect->prepare($query);
        $str->bindParam(':name',$name);
        $str->bindParam(':email',$email);
        $str->execute();
    }
?>


<form method="post">
    Ime
    <input type="text" name="name" id=""><br>
    Mail
    <input type="text" name="email" id="">
    <br><input type="submit" value="Reg">
</form>

<a href="users2.php">List</a>
