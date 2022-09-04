// XHR
var btn = document.getElementById("btn1");

var xhr = new XMLHttpRequest();
xhr.open("GET", "https://api.github.com/emojis");

function hello() {
  if (xhr.readyState == 4) {
    if (xhr.status == 200) {
      loadEmoji(JSON.parse(xhr.responseText));
    }
  }
}

function loadEmoji(data) {
  // make array from the keys
  let keys = Object.keys(data);
  keys.forEach((keys) => {
    let img = document.createElement("img");
    img.src = data[keys];
    document.body.appendChild(img);
  });
}

xhr.addEventListener("readystatechange", hello);

btn.addEventListener("click", () => {
  xhr.send();
});
