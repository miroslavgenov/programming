// using prevent default

var f = document.myform;
var ct = f.cityTxt;

ct.addEventListener("keypress", (e) => {
  if (/[а-я]/.test(e.key)) {
    console.log("correct");
  } else {
    // dont show what i press in the input
    e.preventDefault();
    console.log(e.key);
  }
});
