// izvejda vsichko
var p = document.body.childNodes;
console.log(p);

var h1 = document.body.firstElementChild;
h1.innerText = "Hello";
// print the text empty node
var p1 = h1.nextSibling;
console.log(p1);
p1 = h1.nextElementSibling;
p1.style.color = "red";

var ul = document.getElementsByTagName("ul");
console.log(ul);
ul[0].firstElementChild.style.color = "blue";

var p = document.createElement("p");
p.innerText = "Hello replace";
document.body.replaceChild(p, ul[0].parentElement);
