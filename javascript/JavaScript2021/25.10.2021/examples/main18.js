console.log("hello");
var para = document.querySelectorAll("p");
console.log(para);

// class MyClass {
//   constructor() {
//     this.name = "ivan";
//   }
// }
// var x = new MyClass();
// console.log(x instanceof MyClass);
// var str = "ivan";
// console.log(typeof str);
// console.log(typeof str == "string");

//errror
// for (i in para) {
//   if (para[i] instanceof Node) {
//     para[i]["style"]["color"] = "green";
//   }
// }

// loops
for (i = 0; i < para.length; i++) {
  console.log(para[i]);
  para[i].style.color = "red";
}

for (i of para) {
  i.style.color = "blue";
}

para.forEach((e) => (e.style.color = "orange"));
