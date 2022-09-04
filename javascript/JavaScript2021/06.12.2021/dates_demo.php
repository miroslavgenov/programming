<?php
  date_default_timezone_set('Europe/Sofia');
  $now = date("d-m-Y"); //връща  текущата дата като низ
  //Процедурен подход
  //създаване на дати с date_create 
  $date1= date_create($now);
  $date2= date_create("10-2-2022");
  //Разлика между 2 дати  - функция date_diff()
  $interval1= date_diff($date1, $date2);
  //Форматиране с функции
  echo  date_format( $date1, "d-m-Y")."<br />";
  echo  date_format( $date2, "d-m-Y")."<br />";
  echo  date_interval_format(  $interval1, "Разлика %m месеца %d дни")."<br />";

   echo  date_interval_format(  $interval1, "%a дни")."<br />";

   //Обектно-ориентиран подход
   $date3= new DateTime("24-5-2021");
   $date4= new DateTime("18-3-2022");
   //Разлика между 2 дати  - метод diff()
    $interval2= $date3->diff($date4);
    //Форматиране с метода format()

     echo   $date3->format("d-m-Y")."<br />";
     echo   $date4->format("d-m-Y")."<br />";
     echo   $interval2->format("Разлика %m месеца %d дни")."<br />";
     echo   $interval2->format("%a дни")."<br />"

 
?>