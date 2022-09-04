// making dinamic ul and add li
var ul = document.createElement("ul");
var li1 = document.createElement("li");
var li2 = document.createElement("li");
var li3 = document.createElement("li");

li1.innerText = "li1";
li2.innerText = "li2";
li3.innerText = "li3";

ul.appendChild(li1);
ul.appendChild(li2);
ul.appendChild(li3);

document.body.appendChild(ul);
