<?php 

var_dump($_POST);

if(count($_POST)>0){
    echo "<pre>";
    print_r($_POST);
    echo "</pre>";
    $name = $_POST['name'];
    $email = $_POST ['email'];
    $dt = date("Y.m.d H:i");

    file_put_contents("users.txt","$name,$email,$dt\n",FILE_APPEND);
    $msgOk= "Успешно";

}else{
    $msgEr= "Неуспешно";
}

?>

<form method="post">
    Ime
    <input type="text" name="name" id=""><br>
    Mail
    <input type="text" name="email" id="">
    <input type="submit" value="Reg">
</form>


<?php 

if(isset($msgOk)){
    echo $msgOk;
    echo "<a href=\"users.php\">Spisuk</a>";
}else{
    echo $msgEr;
}

?>