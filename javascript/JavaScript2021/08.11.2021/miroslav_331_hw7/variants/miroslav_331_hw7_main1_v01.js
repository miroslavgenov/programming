var h1Elements = document.querySelectorAll(".dateTime");
var h1ListCurentDateTime = Array.from(h1Elements);

window.addEventListener("load", () => {
  let dt = new Date();
  var dateTimeListString = [
    // for date
    dt.toLocaleDateString(),
    // for time EU 19:30:15
    dt.toTimeString().slice(0, dt.toTimeString().indexOf(" ")),
  ];

  h1ListCurentDateTime.forEach((h1, i) => {
    h1.innerText = dateTimeListString[i];
    h1.style.textAlign = "center";
  });
});

var body = document.body;
body.addEventListener("mouseover", (element) => {
  //   console.log(element.currentTarget);

  if (element.target.tagName === "H3") {
    console.log("hello world");
    console.log(element.target);

    // parseInt
    let shopTimeWorkRange = element.target.nextElementSibling.innerText
      .replace(" ", "")
      .split("-")
      .map((e) => parseInt(e));
    // shopTimeWorkRange = shopTimeWorkRange.map((el) => parseInt(el));

    let currentHourInt = parseInt(
      h1ListCurentDateTime[1].innerText.slice(0, 2)
    );
    //ParseInt
    let div = element.target.parentElement;
    let p = document.createElement("p");
    // let div=element.target.parentNode;
    // if the time is in the working rage then will add open
    if (
      currentHourInt >= shopTimeWorkRange[0] &&
      currentHourInt < shopTimeWorkRange[1]
    ) {
      p.innerText = "Oppen";

      p.style.color = "white";
      p.style.background = "lime";
      p.id = "open";
      div.appendChild(p);
    }
    //   else will add closed
    else {
      p.innerText = "Closed";
      p.style.color = "white";
      p.style.background = "red";
      p.id = "closed";
      div.appendChild(p);
    }
  }
});

body.addEventListener("mouseout", (element) => {
  if (element.target.tagName === "H3") {
    let div = element.target.parentElement;
    div.removeChild(div.lastElementChild);
  }
});
