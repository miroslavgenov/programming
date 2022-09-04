// // . Напишете тест в желаната от Вас предметна област, в който да се
// // използват разгледаните елементи на формата. След приключване на
// // теста да се изведе броя (или процента на верните отговори) и оценката за
// // тест

// var h1Time = document.getElementById("h1Time");
// var f = document.myForm;
// var colorPicker = f.colorPicker;

// colorPicker.addEventListener("change", () => {
//   if (colorPicker.value == "#ff0000") {
//     console.log("correct");
//   }
// });
var btn = document.getElementById("btn");
var myScore = [];
myScore.length = 9;
myScore.fill(0);
console.log(myScore);

var f = document.myForm;
var legent = document.getElementsByTagName("legend")[0];

var a0 = f.answ0;
a0.addEventListener("blur", () => {
  if (a0.value == legent.innerText) {
    myScore[0] = 1;
  } else {
    myScore[0] = 0;
  }
});

// the aswer from how much is the vowel
var a1 = f.answ1;
a1.rows = "1";
a1.setAttribute("placeholder", "xxx , xxx , xxx");

let vowels = ["о", "е", "а"];

a1.addEventListener("change", () => {
  if (/о\,е\,а/.test(a1.value)) {
    myScore[1] = 1;
  } else {
    myScore[1] = 0;
  }
});

//answer 3
var divRadioGroup = document.querySelector("#divRadioGroup");
divRadioGroup.addEventListener("click", (event) => {
  if ((event.target.type = "radio")) {
    if (event.target.value == "1") {
      myScore[2] = 1;
    } else {
      myScore[2] = 0;
    }
  }
  // console.log(myScore);
});

//checkbox
var checkbox = Array.from(f.checkbox);

checkbox.forEach((el) => {
  el.addEventListener("click", (event) => {
    if (event.target.checked && event.target.value == "1") {
      myScore[3] = 1;
    } else if (event.target.checked != true) {
      myScore[3] = 0;
      // but if there is the other checkbox with value 1 checked
      // the score is correct
      checkbox.forEach((boxe) => {
        if (boxe.value == "1" && boxe.checked == true) {
          myScore[3] = 1;
        }
      });
    }
    console.log(myScore);
  });
});

// select month
var select = f.answ4;
select.addEventListener("click", () => {
  if (select.selectedIndex == "2") {
    myScore[4] = 1;
  } else {
    myScore[4] = 0;
  }
});

// color
var colorPicker = f.answ5;
colorPicker.addEventListener("change", () => {
  if (colorPicker.value == "#ff0000") {
    myScore[5] = 1;
  } else {
    myScore[5] = 0;
  }
  console.log(myScore);
});

// answer 6
var range = f.answ6;
var output = f.result6;
range.addEventListener("input", () => {
  output.value = parseInt(range.value);
  if (parseInt(range.value) == 9) {
    myScore[6] = 1;
  } else {
    myScore[6] = 0;
  }
});

//answer7
var number = f.answ7;
number.addEventListener("change", () => {
  if (number.value == "31") {
    myScore[7] = 1;
  } else {
    myScore[7] = 0;
  }
});

var selectM = f.answ8;
var options = Array.from(selectM);
selectM.addEventListener("blur", () => {
  if (selectM.options[0].selected && selectM.options[1].selected) {
    myScore[8] = 1;
  } else {
    myScore[8] = 1;
  }
});

var divQuest = document.getElementsByClassName("question");
var divQ = Array.from(divQuest);
var field = document.getElementsByTagName("fieldset")[0];

var h3Result = document.createElement("h3");
var pRes=document.createElement("p");

function getCalcResult() {
  var scoreResult = myScore.reduce((s, e) => (e == 1 ? s + 1 : s + 0));
  return scoreResult;
}

function clearField() {
  let clearEl = Array.from(field.children);
  clearEl.forEach((e) => {
    field.removeChild(e);
  });
}

function setUpFinalResult() {
  clearField();
  h3Result.innerHTML = `Точки: ${getCalcResult()}`;
  pRes.innerText="Отговори";
  let pdfAnswers = document.createElement("object");
  pdfAnswers.data = "answers.pdf";
  pdfAnswers.height = "400px";
  pdfAnswers.id = "pdf";

  pdfAnswers.type = "application/pdf";
  field.appendChild(h3Result);
  field.appendChild(pRes);
  field.appendChild(pdfAnswers);
  btn.style.display = "none";
  clearInterval(id);
}

btn.addEventListener("click", () => {
  setUpFinalResult();
});

var id;
window.addEventListener("load", () => {
  id = setInterval(() => {
    h1Time.innerText = parseInt(h1Time.innerText) - 1;
    if (parseInt(h1Time.innerText) == 0) {
      setUpFinalResult();
    }
  }, 30000);
});
