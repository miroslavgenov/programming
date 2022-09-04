var h1Time = document.getElementsByTagName("h1")[0];

var num = 10;

var id = window.setInterval((e) => {
  num -= 1;
  h1Time.innerText = String(num);
  if (num == 0) {
    clearInterval(id);
    console.log(num);
    document.body.style.display = "none";
    document.write("<h1>your score is 10</h1>");
  }
}, 500);
