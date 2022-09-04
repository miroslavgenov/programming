var f = document.myform;
var div = document.getElementsByName("extras")[0];

var sum = 0;

div.addEventListener("click", (e) => {
  //tagName show what is the html tag
  // if the element is p then will show p
  // if the element have type then will show the type if the
  // p type is text will show only the elements with type text
  if (e.target.type == "checkbox") {
    // console.log(e.target.value);
    // console.log(e.target.parentElement.innerText);

    if (e.target.checked) {
      console.log(e.target.value);
      sum += parseInt(e.target.value);
    } else {
      sum -= parseInt(e.target.value);
    }
    f.total.value = sum;
  }
});
