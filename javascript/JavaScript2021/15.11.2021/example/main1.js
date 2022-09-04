var f = document.forms[0];

//evemt change
f.addEventListener("change", () => {
  console.log("change");
});

//evemt submit
// when i enter in input text enter
// or click on button submit
f.addEventListener("submit", () => {
  console.log("submit");
});
