// replace child ul
var list = [];

for (let i = 0; i < 4; i++) {
  if (i == 0) {
    list.push(document.createElement("ul"));
  } else {
    list.push(document.createElement("li"));
  }
}

var count = 1;
for (i of list.slice(1)) {
  i.innerText = "list Gen " + count;
  count++;
  list[0].appendChild(i);
}

var ul = document.querySelector("ul");
var div = document.querySelector("div");

div.replaceChild(list[0], ul);
