//Preki metodi
console.log(document.getElementsByTagName("body"));
var body = document.body;

var p = body.getElementsByTagName("p");
console.log(p);

var arr_p = Array.from(p);

console.log(arr_p);

arr_p.forEach((el) => console.log(el));
