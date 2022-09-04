//insertBefore add before (like unshift)
// appendChild add affter (like push)
var p = document.createElement("li");
p.innerText = "insertBefore";
var ul = document.querySelector("ul");
document.body.insertBefore(p, document.body.firstChild);
// error this is not child of th body this is another container
// document.body.insertBefore(p, ul.firstChild);
