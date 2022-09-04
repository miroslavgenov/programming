var form1 = document.getElementById("form1");
var input1 = document.getElementById("input1");
var input2 = document.getElementById("input2");
var xhr = new XMLHttpRequest();
xhr.open("POST", "miroslav_331_hw_9_index.php");
xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

form1.addEventListener("submit", (e) => {
  e.preventDefault();
  //   console.log(input1.value, input2.value);
  xhr.send("myData=" + [input1.value.replace(",", " "), input2.value]);
});

xhr.addEventListener("load", hello);

function hello() {
  if (xhr.status == 200) {
    console.log(xhr.responseText);
  }
}
