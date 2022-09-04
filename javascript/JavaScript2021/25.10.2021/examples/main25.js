// remove child
var ul = document.querySelector("ul");
ul.removeChild(ul.children[0]);
ul.children[0].remove();

ul.removeChild(ul.children[0]);

var li = document.createElement("li");
li.innerText = "item 1";
//!!
ul.appendChild(li);
// !!!!
ul.removeChild(li);
