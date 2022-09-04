//
console.log(document.getElementsByName("message"));

var p_msg = Array.from(document.getElementsByName("message"));
p_msg[0].textContent = "hello worldxx";
