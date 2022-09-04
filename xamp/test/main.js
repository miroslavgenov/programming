var x = new XMLHttpRequest();
x.open("get", "main.php");
var form = document.getElementsByTagName("form")[0];

x.addEventListener("load", hello);
function hello() {
  console.log(x.responseText);
}

form.addEventListener("submit", (e) => {
  x.send();

  e.preventDefault();
});
