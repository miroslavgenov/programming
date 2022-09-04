var div = document.getElementById("d1");
const myKyes = ["A", "W", "D", "S"];
var img = document.createElement("img");
img.src = "img.png";

//div.replaceWith(img)
document.body.replaceChild(img, div);

function checkEvent(e) {
  if (e.type == "click") {
    move(e.clientY, e.clientX);
  }

  if (e.type == "keydown") {
    var style = getComputedStyle(img);
    var currentTop = style.top;
    var currentLeft = style.left;
    console.log(e.code.slice(-1));
    switch (e.code.slice(-1)) {
      case myKyes[0]:
        move(parseInt(currentTop), parseInt(currentLeft) - 50);
        break;
      case myKyes[1]:
        move(parseInt(currentTop) - 50, parseInt(currentLeft));
        break;
      case myKyes[2]:
        move(parseInt(currentTop), parseInt(currentLeft) + 50);
        break;
      case myKyes[3]:
        move(parseInt(currentTop) + 50, parseInt(currentLeft));
        break;
    }
  }
}

function move(top, left) {
  img.style.top = top + "px";
  img.style.left = left + "px";
}

document.addEventListener("click", checkEvent);
document.addEventListener("keydown", checkEvent);
