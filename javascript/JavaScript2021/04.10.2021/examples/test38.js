// closuer
var number = function () {


    var counter = 0;
    // console.log("Counter= ", counter)
    return function () {
        // console.log("Inner counter", counter);
        return counter++;
    };
};

console.log(number())
console.log(number())
console.log(number()())
console.log(number()())

var res = number();
console.log(res())
console.log(res())
res;
console.log(res())

