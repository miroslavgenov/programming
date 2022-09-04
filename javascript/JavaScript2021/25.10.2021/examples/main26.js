// clone node with child
console.log("hello world");
var ul = document.querySelector("ul");
var ul_clone = ul.cloneNode(true);
ul.removeChild(ul.children[0]);
ul.firstChild.remove();

var div = document.querySelector("div");
div.appendChild(ul_clone);
