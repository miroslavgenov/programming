var xhr = new XMLHttpRequest();
console.log(xhr);
console.log("xhr status", xhr.status);
console.log("before open", xhr.readyState);
xhr.open("GET", "ip_test.js", true);
console.log("after open", xhr.readyState);
console.log("xhr status", xhr.status);

xhr.send();

// frushta window elementa
// xhr.addEventListener("readystatechange", () => {
// console.log(this);
// });

// this e XMLHTTPREQUES object-ta
xhr.addEventListener("readystatechange", hello);
function hello() {
  console.log();
  console.log(this.readyState);
  console.log(this.status);
  console.log();

  if (this.readyState == 4) {
    if (this.status == 200) {
      console.log("hello world");
      console.log(this.responseText);
    }
  }
}

// same as the example with the hello
// xhr.onreadystatechange = function () {
// console.log(this);
// };
