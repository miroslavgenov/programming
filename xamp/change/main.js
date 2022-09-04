var form2 = document.getElementsByTagName("button")[0];
var xhr = new XMLHttpRequest();

xhr.addEventListener("load", hello);

function hello() {
  if (xhr.status == 200) {
    console.log(xhr.responseText);
    document.body.innerHTML = xhr.responseText;
  }
}

form2.addEventListener("click", (e) => {
  xhr.open("GET", "get.php");
  xhr.send();
});
