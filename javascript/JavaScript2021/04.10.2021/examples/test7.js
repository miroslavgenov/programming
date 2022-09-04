function hello() {
    return 'hello';
}

var result1 = (function () { return 1; });
var result2 = function () { return 1; };
console.log(result1())
console.log(result2())

var result3 = function hello1() { return 'hello' };
console.log(result3())



var result4 = (function hello2() { return 'hello1'; });
console.log(result4())

console.log(typeof hello());
console.log(typeof result3);
console.log(typeof result4());


