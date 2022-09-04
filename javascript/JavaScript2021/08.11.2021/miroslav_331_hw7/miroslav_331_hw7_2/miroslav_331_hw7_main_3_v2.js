var input = document.createElement("input");
var body = document.body;

input.type = "text";
body.appendChild(input);

input.addEventListener("keypress", (event) => {
  event.preventDefault();
  input.value += String.fromCharCode(event.charCode).toUpperCase();
});
