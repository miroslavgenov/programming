var ul = document.querySelector("ul");
var div = document.querySelector("div");

var p1 = document.createElement("p");
p1.innerHTML = "<b>innerHTML</b> <i>insert</i> before ul";
div.insertBefore(p1, ul);
