// ---> e strelka
// firstElementChildlastElementChild    Body    lastElementChild
//     |                                  |            |
//     |                                  |            |
//     |                               children        |
//     v                                  v            v
//    div                                 Ul          div
var n1 = document.body.firstChild;
console.log("n1=>", n1);
console.log();
var n2 = document.body.childNodes[1];
console.log("n2=>", n2);
console.log();
var n3 = document.body.lastChild;
console.log("n3=>", n3);
console.log();

// tova e ekvivalentno na no vzma i praznite tekstovi vruzki
// vzima purviq element
var h1 = document.body.firstElementChild;
console.log(h1);
//vzima srednite elementi
var p1 = document.body.children[1];
console.log(p1);
//vzima posledniq element
var div = document.body.lastElementChild;
console.log(div);
