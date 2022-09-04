// value of the leva to store
var currency = " lv";

// array which have objects to store date for the order
var orderList = [
  { size: null, price: 0, index: 0 },
  { color: null },
  [
    { extra: "Gift Box", price: 0 },
    { extra: "Add Stamp", price: 0 },
    { extra: "Home delivery", price: 0 },
  ],
  { address: null },
  { tel: null },
];

// reference to form
var formOrder = document.orderForm;
console.log(formOrder);

// here we will store the price
// inputPriceText;
var inputPriceText = formOrder.inputPriceText;
inputPriceText.value = "";

//console.log(document.forms[0].style.top);

// reference to <select>
var selectSizes = formOrder.selectSizes;

// default price text at index 0
inputPriceText.value =
  selectSizes.options[selectSizes.selectedIndex].value + currency;

orderList[0]["size"] = selectSizes.options[0].text;
orderList[0]["price"] = parseInt(selectSizes.options[0].value);
orderList[0]["index"] = parseInt(selectSizes.selectedIndex);

// event listener will change the price if choosen diferent size
selectSizes.addEventListener("change", () => {
  // this is when i click again to change the size of
  // the t shirt and have selecter Gift and Stamp
  orderList[0]["price"] -= parseInt(
    selectSizes.options[orderList[0]["index"]].value
  );

  //adding the new data
  orderList[0]["size"] = selectSizes.options[selectSizes.selectedIndex].text;
  orderList[0]["price"] = parseInt(
    selectSizes.options[selectSizes.selectedIndex].value
  );
  orderList[0]["index"] = parseInt(selectSizes.selectedIndex);
  console.log(orderList);
  ///!!!
  let sumExtras = null;
  orderList[2].forEach((e, i) => {
    sumExtras += e["price"];
  });

  // inputPriceText;

  inputPriceText.value = parseInt(orderList[0]["price"] + sumExtras) + currency;
});

// div with radio buttons

// only for addEventListener clisk is used
var divRadioShirtColor = document.querySelector("div#divRadioShirtColor");
var img = document.querySelector("img");

var shirtColorsString = Array.from(orderForm.radioShirtColor);
// console.log(shirtColorsString);
//

var imgType = ".png";
shirtColorsString = shirtColorsString.map((e) => e.value + imgType);

console.log(shirtColorsString);
let currentColo;

divRadioShirtColor.addEventListener("click", (e) => {
  if (e.target.type == "radio") {
    // getting the clicked color from the radio button and
    // stores the clicked img png file
    let currentColor = shirtColorsString
      .filter((color) => {
        // now will  be without 'png'   be only red to check if its equal
        // and will return red.png
        return color.slice(0, -imgType.length) == e.target.value;
      })
      .join();

    img.className = "show";
    orderList[1]["color"] = currentColor.slice(0, -imgType.length);
  }
});

var radioBtn = Array.from(orderForm.radioShirtColor);
radioBtn.forEach((e) => {
  e.addEventListener("mouseover", () => {
    img.src = e.value + imgType;
    img.className = "show";
  });
  e.addEventListener("mouseout", () => {
    // img.src = e.value + imgType;
    img.className = "hide";
  });
});

var divCheckBox = document.querySelector("#divCheckBox");
var checkboxExtra = Array.from(orderForm.checkboxExtra);
console.log(checkboxExtra);

var sumCheckbox = 0;
divCheckBox.addEventListener("click", (e) => {
  if ((e.target.type = "checkbox")) {
    if (e.target.checked) {
      console.log(e.target.value);
      //to add the prices clicked
      orderList[2].forEach((objectExtra) => {
        if (
          objectExtra["extra"] == e.target.parentElement.innerText.trimEnd() //to trip the back space
        ) {
          objectExtra["price"] = parseInt(e.target.value);
          sumCheckbox += parseInt(objectExtra["price"]);
        }
      });
      console.log(orderList[0]["price"]);
      inputPriceText.value =
        parseInt(orderList[0]["price"] + sumCheckbox) + currency;

      //   console.log(e.target.parentElement.innerText == orderList[2][2]["extra"]);
    } else {
      orderList[2].forEach((objectExtra) => {
        if (
          objectExtra["extra"] == e.target.parentElement.innerText.trimEnd()
        ) {
          sumCheckbox -= objectExtra["price"];
          objectExtra["price"] = 0;
        }
        inputPriceText.value =
          parseInt(orderList[0]["price"] + sumCheckbox) + currency;
      });
    }
  }
  console.log(orderList);
});

// address
var inputAddress = orderForm.inputAddress;
console.log(inputAddress.value);
inputAddress.addEventListener("blur", (e) => {
  if (!inputAddress.value) {
    inputAddress.style.borderColor = "red";
  } else {
    orderList[3]["address"] = inputAddress.value;
  }
});

var inputTel = orderForm.inputTel;
console.log(inputTel.value);
inputTel.addEventListener("blur", (e) => {
  if (!inputTel.value) {
    inputTel.style.borderColor = "red";
  } else if (!/\d{4} (\d{2} ?){3}/.test(inputTel.value)) {
    inputTel.style.borderColor = "red";
  } else {
    orderList[4]["tel"] = inputTel.value;
  }
});
console.log(orderList);
console.log(orderList);

var btn = document.getElementsByTagName("button")[0];

let overSum = 0;

// create div to show order List preview
let orderListPrevioDiv = document.createElement("div");
orderListPrevioDiv.id = "orderListPreview";

// create H1
let h1Preview = document.createElement("h1");
h1Preview.innerText = "Order List Preview";
orderListPrevioDiv.appendChild(h1Preview);

//working variant
// btn.addEventListener("click", () => {
//   for (i in orderList[0]) {
//     let p = document.createElement("p");
//     if (i == "size") {
//       // store the size and razmer

//       p.innerHTML = `<b>${i.replace(
//         i.slice(0, 1),
//         i.slice(0, 1).toUpperCase()
//       )}:</b> ${orderList[0][i]}`;
//       orderListPrevioDiv.appendChild(p);
//     }
//   }
//   let pColor = document.createElement("p");
//   let srtColor = Object.keys(orderList[1]).join();
//   srtColor = srtColor.replace(
//     srtColor.slice(0, 1),
//     srtColor.slice(0, 1).toUpperCase()
//   );
//   pColor.innerHTML = `<b>${srtColor}:</b> ${
//     orderList[1][Object.keys(orderList[1])]
//   } <img id='imgPreview' src='${
//     orderList[1][Object.keys(orderList[1])] + imgType
//   }'>`;
//   orderListPrevioDiv.appendChild(pColor);

//   // algorith to check if stamp is selected !!

//   for (i in orderList[2]) {
//     for (j in orderList[2][i]) {
//       if (!isNaN(orderList[2][i][j])) {
//         // if value of the extra is !=0 this meat that is selected
//         if (orderList[2][i][j] != 0) {
//           let p = document.createElement("p");
//           p.innerHTML = `<u><i>${orderList[2][i]["extra"]}</i></u>`;
//           orderListPrevioDiv.appendChild(p);
//         }
//       }
//     }
//   }

//   let pAddress = document.createElement("p");
//   pAddress.innerHTML = `<b>${Object.keys(orderList[3])
//     .join()
//     .replace("a", "A")}:</b>  <i>${orderList[3]["address"]}<i>`;
//   orderListPrevioDiv.appendChild(pAddress);

//   let pTel = document.createElement("p");
//   pTel.innerHTML = `<b>${Object.keys(orderList[4])
//     .join()
//     .replace("t", "T")}:</b> <i>${orderList[4]["tel"]}</i>`;
//   orderListPrevioDiv.appendChild(pTel);

//   let h4Price = document.createElement("h4");
//   h4Price.innerHTML = `Price: ${inputPriceText.value} ${currency}<br><hr>`;
//   orderListPrevioDiv.appendChild(h4Price);

//   document.body.appendChild(orderListPrevioDiv);
// });

// recursive function to store all the keys from orderList
function showKeys(obj1) {
  obj1.forEach((element, elindex) => {
    if (!Array.isArray(element)) {
      // stores the keys from the object
      let myKeys = [];
      myKeys = myKeys.concat(Object.keys(element));
      myKeys.forEach((key, idx, arrayK) => {
        //this is if you forget to add address or number or color
        if (element[key] !== null) {
          // this is for the extras
          if (element[key] == 0) {
            // let p = document.createElement("p");
            // console.log(key, element[key]);
            // p.innerText = element[arrayK[idx - 1]] + " " + element[key];
            // document.body.appendChild(p);
          } else {
            // here if the price of the extra is !=0 then will show
            // else will not show
            if (element[arrayK[idx + 1]] != 0) {
              if (key != "price" && key != "index") {
                let p = document.createElement("p");
                console.log(key, element[key]);
                p.innerText = key + " " + element[key];
                orderListPrevioDiv.appendChild(p);
                if (key == "color") {
                  // adding the img to the view
                  let img = document.createElement("img");
                  img.src = element[key] + imgType;

                  orderListPrevioDiv.appendChild(img);

                  // console.log(key);
                }
              }
            }
          }
        } else {
          //window.confirm("Липсва информация");
        }
      });
      // while we have the keys now we will loop trought the
      // order list
    } else {
      // if the element is not array then is object
      // and will call recursivly to store the
      // nested data
      showKeys(element);
    }
  });
}

// working variant
btn.addEventListener("click", () => {
  showKeys(orderList);
  let pPrice = document.createElement("p");
  pPrice.innerText = inputPriceText.value;
  let hr = document.createElement("hr");
  hr.style.width = "50%";
  orderListPrevioDiv.appendChild(pPrice);
  orderListPrevioDiv.appendChild(hr);

  document.body.appendChild(orderListPrevioDiv);
});
