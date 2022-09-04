
// you can call before and after
console.log(mySum1(2, 2));
function mySum1(a, b) {
    return a + b;
}
console.log(mySum1(1, 2));


// console.log(mySum2(3, 3));

var mySum2 = function (x, y) { return x + y; };

console.log(mySum2(3, 3));





console.log()
//x dos not change
var x = 10;

console.log("x=", x)

function mult() {

    return x * 2;
}
console.log(mult())
console.log("x doesn't change", x)


console.log()

x = 10;

function div() {
    var x = 100;
    return x / 2;
}

console.log(div())
console.log("again x doesn't change")
console.log(x)













