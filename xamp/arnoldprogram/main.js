var imgs = document.getElementsByTagName("img");

var imgTT0 = document.getElementById("h1MenuTextExercise");
var imgTT2 = document.getElementById("h1MenuTextPlan");
var imgTT3 = document.getElementById("h1MenuTextDiet");

var imgMenu = Array.from(imgs).slice(0, 4);
console.log(imgMenu);

document.addEventListener("mouseover", (e) => {
  if (e.target.id === "imgTraining" || e.target.id === "h1MenuTextExercise") {
    imgMenu[0]["style"]["animation-name"] = "imgTrainingAnimation1";

    imgTT0["style"]["visibility"] = "visible";
    imgTT0["style"]["animation-name"] = "trainintTextAnimation1";
  }

  if (e.target.id === "imgDiet" || e.target.id === "h1MenuTextDiet") {
    imgMenu[3]["style"]["animation-name"] = "imgTrainingAnimation1";
    imgTT3["style"]["visibility"] = "visible";
    imgTT3["style"]["animation-name"] = "trainintTextAnimation1";
  }
  if (e.target.id === "imgPlan" || e.target.id === "h1MenuTextPlan") {
    imgMenu[2]["style"]["animation-name"] = "imgTrainingAnimation1";
    imgTT2["style"]["visibility"] = "visible";
    imgTT2["style"]["animation-name"] = "trainintTextAnimation1";
  }
});

document.addEventListener("mouseout", (e) => {
  if (e.target.id === "imgTraining") {
    imgMenu[0]["style"]["animation-name"] = "imgTrainingAnimation2";
    e.target["style"]["filter"] = "contrast(150%)";

    imgTT0["style"]["animation-name"] = "trainintTextAnimation2";
    console.log(imgTT0);
  }

  if (e.target.id === "imgDiet") {
    imgTT3["style"]["visibility"] = "visible";
    imgTT3["style"]["animation-name"] = "trainintTextAnimation2";
    imgMenu[3]["style"]["animation-name"] = "imgTrainingAnimation2";
  }
  if (e.target.id === "imgPlan") {
    imgTT2["style"]["visibility"] = "visible";
    imgTT2["style"]["animation-name"] = "trainintTextAnimation2";
    imgMenu[2]["style"]["animation-name"] = "imgTrainingAnimation2";
  }
});

imgs[2].addEventListener("click", (e) => {
  document.location.href = "http://localhost/arnoldprogram/plan.php";
});

// img1.addEventListener("click", () => {
// document.location = "http://localhost/arnoldprogram/training.html";
// });
