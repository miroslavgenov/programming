// show the whole html document
// access the document
console.log(document);
console.log();
// show what is in the body tag
//access to document
console.log(document.body);
console.log();

var body = document.body;
console.log("typeof body -> ", typeof body);
console.log();

// relatioship parent child
// and return all childrens of the
// body with empty text nodes
console.log(body.childNodes);
console.log("type of body.childNodes", typeof body.childNodes);
console.log();

// body.children dava vlojenite elementi direktno v children
// this body.children is like list
var children = body.children;
console.log(children);
console.log("typeof children -> ", typeof children);
console.log("children.lenght= ", children.length);
console.log(children[5]);
console.log();

function hello() {
  this.alert("hello world !");
  this.confirm("hello world ?");
  //error
  // this.input();
}
// hello();

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
