// using Array.from
console.log("hello from main19");
var pAll = document.querySelectorAll("p");
var pAllList = Array.from(pAll);

for (i = 0; i < pAllList.length; i++) {
  pAllList[i].style.color = "red";
}

for (i in pAllList) {
  pAllList[i].style.color = "orange";
}

for (i of pAllList) {
  i.style.color = "yellow";
}

pAllList.forEach((e) => {
  e.style.fontSize = "20px";
  e.style.color = "black";
});
