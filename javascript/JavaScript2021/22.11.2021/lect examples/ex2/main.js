var button = document.getElementById("btn");
var xhr = new XMLHttpRequest();

function getInfo() {
  if (xhr.readyState == 4 && xhr.status == 200) {
    console.log(xhr.responseText);
  }
}

xhr.addEventListener("readystatechange", getInfo);

button.addEventListener("click", () => {
  xhr.open("GET", "javascript.js");
  xhr.send();
});
