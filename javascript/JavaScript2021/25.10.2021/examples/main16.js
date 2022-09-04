var ul = document.querySelector("ul");
var li1 = document.createElement("li");
var li2 = document.createElement("li");
var li3 = document.createElement("li");
li1.innerText = "ul.insertBefore(li1, ul.firstChild);";
li2.innerText = "ul.appendChild(li2);";
li3.innerText = "ul.insertBefore(li3, ul.children[2]);";
//

// insertBefore the first element of the ul
ul.insertBefore(li1, ul.firstChild);
ul.appendChild(li2);
ul.insertBefore(li3, ul.children[2]);

// change oformlenie
ul.children[1].innerHTML = "change oformlenie";
ul.children[1].style.color = "blue";
