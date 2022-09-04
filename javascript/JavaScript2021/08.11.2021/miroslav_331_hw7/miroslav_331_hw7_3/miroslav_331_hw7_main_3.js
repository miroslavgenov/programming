const div = document.createElement("div");

const text = document.createElement("p");

text.innerText = "Mouve over me!!";
div.appendChild(text);
document.body.appendChild(div);

div.addEventListener("mouseover", (e) => {
  div.style.backgroundColor = "lightgreen";
  div.style.border = "2px solid";
  div.style.width = "220px";
  div.style.height = "150px";
  text.style.color = "white";
  text.style.fontWeight = "bold";
  text.style.fontSize = "40px";
  text.style.textAlign = "center";
});

div.addEventListener("mouseout", (e) => {
  div.style.backgroundColor = "";
  text.style.fontSize = "";
  text.style.color = "";
  div.style.border = "";
  text.style.fontWeight = "";
  text.style.textAlign = "";
});
