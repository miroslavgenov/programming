// 3. Даден е масив с имена на стоки и техните цени:
// var goods = ["Компютър:1200 лв", "Принтер:230лв", "Мишка:15 лв"];
// Напишете регулярен израз, с помощта на който извлечете цените на стоките като числа (без  лв) и ги
// запишете в отделен масив.

console.log("Exercise 3");

var goods = ["Компютър:1200 лв", "Принтер:230лв", "Мишка:15 лв"];

console.log("var reg = /^[а-я]+:(d+) лв/gi;");
var reg = /^[а-я]+:(\d+) лв/gi;

var lev = [];

goods.forEach((e) => {
  if (reg.test(e)) {
    lev.push(Number(RegExp.$1));
  }
});

console.log(lev);

console.log("end Exercise 3");
console.log();
