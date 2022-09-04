// password

var f = document.myform;
var pass = f.passTxt;

pass.addEventListener("change", (e) => {
  if (pass.value.length < 6) {
    console.log("less then 6");
  } else if (!/\W/.test(pass.value)) {
    console.log("need to be symbols");
  } else {
    console.log("correct");
  }
});
