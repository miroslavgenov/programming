var img0 = document.getElementsByTagName("img")[0];
var img1 = document.getElementsByTagName("img")[1];

img0.addEventListener("animationiteration", (e) => {
  var currentAnimation = img0.getAnimations()[0]["animationName"];
  console.log(currentAnimation);
  if (currentAnimation === "slide") {
    img0["style"]["animation-name"] = "slide1";
  }
  if (currentAnimation === "slide1") {
    img0["style"]["animation-name"] = "slide";
  }
});

img1.addEventListener("animationiteration", (e) => {
  var currentAnimation = img1.getAnimations()[0]["animationName"];
  if (currentAnimation === "slide1") {
    img1["style"]["animation-name"] = "slide";
  }
  if (currentAnimation === "slide") {
    img1["style"]["animation-name"] = "slide1";
  }
});
