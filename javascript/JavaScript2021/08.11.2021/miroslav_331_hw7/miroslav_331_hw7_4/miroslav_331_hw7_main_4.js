var body = document.body;
style = getComputedStyle(body);
let pinkColor = style.backgroundColor;
body.addEventListener("keydown", (e) => {
  if (e.keyCode == 86) {
    body.style.backgroundColor = "purple";
  }
});

body.addEventListener("keyup", (e) => {
  if (e.keyCode == 86) {
    body.style.backgroundColor = pinkColor;
  }
});
