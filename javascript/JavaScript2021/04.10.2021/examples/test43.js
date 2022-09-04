function f(param) {
    var n = function () {
        return param++;
    };
    return n;
}

console.log(f(10)());
console.log(f(10)());

var nums = f(10);
nums();
nums();
console.log(nums());
