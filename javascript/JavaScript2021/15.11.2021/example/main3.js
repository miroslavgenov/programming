// blur examples with and regexp

var f = document.forms[0];
var cT = f.cityTxt;

cT.addEventListener("blur", () => {
  //   console.log(/\W/.test(cT.value));
  let reg = /\W/;
  if (reg.test(cT.value)) {
    console.log("match");
  }
});
