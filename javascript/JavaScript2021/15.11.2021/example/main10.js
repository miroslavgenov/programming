var f = document.myform;
var t1 = f.total1;
var div = document.getElementById("divRadio");
var radio = Array.from(document.getElementsByName("room"));

console.log(radio.filter((e) => e.checked == true));

console.log(t1);

div.addEventListener("click", (e) => {
  if ((e.target.type = "radio")) {
    // t1.value = e.target.value;
    t1.value = document.querySelector('input[name="room"]:checked').value;
  }
});
