var input = document.createElement("input");
var button = document.createElement("button");

button.innerText = "Add";

document.body.appendChild(input);
document.body.appendChild(button);

button.addEventListener("click", () => {
  let p = document.createElement("p");
  p.innerText = input.value;
  document.body.appendChild(p);
  input.value = "";
});
