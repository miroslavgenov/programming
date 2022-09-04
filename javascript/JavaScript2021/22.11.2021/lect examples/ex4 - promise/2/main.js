// var isHappy = false;
var isHappy = true;

var willGetNewPhone = new Promise(function (resolve, reject) {
  if (isHappy) {
    var phone = {
      brand: "Samsung",
      color: "black",
    };
    setInterval(() => {
      resolve(phone);
    }, 2000);
  } else {
    var reason = new Error("mom is engry");
    setInterval(() => {
      reject(reason);
    }, 1000);
  }
});

willGetNewPhone
  .then((value) => console.log(value))
  .catch((value) => console.log(value));
