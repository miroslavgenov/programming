// FETCH
var btn = document.getElementById("btn1");

async function getEmoji(url) {
  var data = await fetch(url);
  if (data.ok) {
    data = await data.text().then((val) => val);
    for (k in JSON.parse(data)) {
      let img = document.createElement("img");
      img.src = JSON.parse(data)[k];
      document.body.appendChild(img);
    }
  }
}

btn.addEventListener("click", () => {
  getEmoji("https://api.github.com/emojis");
});
