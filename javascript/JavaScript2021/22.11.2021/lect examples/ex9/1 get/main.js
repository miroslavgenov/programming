var form2 = document.getElementById("form2");
var xhr = new XMLHttpRequest();
var input = document.getElementById("msg2");

xhr.addEventListener("load", hello);

function hello() {
  if (xhr.status == 200) {
    console.log(xhr.responseText);
  }
}

form2.addEventListener("submit", (e) => {
  e.preventDefault();
  xhr.open("GET", "get.php?" + input.name + "=" + input.value);
  xhr.send();
});
