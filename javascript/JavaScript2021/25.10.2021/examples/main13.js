// dobavqne na element i sudurjanie
var p = document.createElement("p");
p.innerText = "<b>innerText</b>";
var div = document.querySelector("div");
document.body.insertBefore(p, div);

var p1 = document.createElement("p");
p1.innerHTML = "<b>innerHtml</b>";

document.body.insertBefore(p1, div);
