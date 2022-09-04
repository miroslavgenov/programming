var form1 = document.getElementById("form1");
var input1 = document.getElementById("input1");
var xhr = new XMLHttpRequest();
xhr.open("POST", "readDb.php");
xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

form1.addEventListener("submit", (e) => {
  e.preventDefault();
  //   console.log(input1.value);
  xhr.send(input1.name + "=" + input1.value);
});

xhr.addEventListener("load", hello);
function hello() {
  if (xhr.status == 200) {
    console.log(xhr.responseText);
  }
}
