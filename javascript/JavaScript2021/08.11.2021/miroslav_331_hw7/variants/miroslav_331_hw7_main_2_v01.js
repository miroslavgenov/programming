var input = document.createElement("input");
var body = document.body;

input.type = "text";
body.appendChild(input);
var string = "";

input.addEventListener("keypress", (event) => {
  if (typeof input.value == "string") {
    let upper = String.fromCharCode(event.charCode).toUpperCase();

    if (parseInt(String.fromCharCode(event.charCode))) {
      input.value = "";
      string += String.fromCharCode(event.charCode);
      input.value = string;
    } else {
      input.value = "";
      string += upper;
      input.value = string;
    }
  }
});
