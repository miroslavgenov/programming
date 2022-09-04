// var input = document.querySelector("input");
var button = document.createElement("button");
button.innerText = "CLICK ME";

document.body.appendChild(button);

button.addEventListener("click", () => (button.innerText = "Hello world!"));
