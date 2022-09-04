var b0 = document.getElementById("bl0");
var b1 = document.getElementById("bl1");
var b2 = document.getElementById("bl2");
var b3 = document.getElementById("bl3");

var animatedElements = [b0, b1, b2, b3];
animatedElements.forEach((element) => {
  console.log(element.getAnimations()[0]["animationName"]);
});

b1.addEventListener("animationiteration", (e) => {
  var currentAnimation = b1.getAnimations()[0]["animationName"];
  console.log(currentAnimation);
  if (currentAnimation === "slide1") {
    b1["style"]["animation-name"] = "slide2";
  }
  if (currentAnimation === "slide2") {
    b1["style"]["animation-name"] = "slide3";
  }
});
