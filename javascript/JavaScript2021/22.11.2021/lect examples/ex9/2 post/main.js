var form2 = document.getElementById("form2");
var xhr = new XMLHttpRequest();
xhr.open("POST", "post.php");

form2.addEventListener("submit", (e) => {
  var input2 = document.getElementById("input2");
  e.preventDefault();
  xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  xhr.send(input2.name + "=" + input2.value);
});

xhr.addEventListener("load", hello);

function hello() {
  if (xhr.status == 200) {
    console.log(xhr.responseText);
  }
}
