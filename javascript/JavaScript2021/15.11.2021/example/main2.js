// focus , blur event for input text
var f = document.myform;
var cTxt = f.cityTxt;

// focus - used for input type=text and when
// you click on it is when you focus
cTxt.addEventListener("focus", (e) => {
  console.log("you focus City");
});

//blur
// when you are in focus and then you click somewhere else
// and the focus is gone then is the blur
cTxt.addEventListener("blur", (e) => {
  console.log("you blur City");
});
//preventdefault
