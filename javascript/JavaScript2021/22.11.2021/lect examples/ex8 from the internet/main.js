// var xhr = new XMLHttpRequest();

// xhr.open("GET", "https://api.github.com/users");
// xhr.send();
// xhr.addEventListener("load", hello);

// function hello() {
//   if (this.status == 200) {
//     var info = JSON.parse(this.responseText);
//     console.log(info);
//   }
// }

getData("https://api.github.com/users").then((val) => console.log(val));

async function getData(url) {
  var result = await fetch(url);
  if (result.ok) {
    return await result.json();
  }
}
