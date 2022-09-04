var f = function () { };
var p = f.prototype;
var c = p.constructor;

console.log(c === f)
console.log(p === f)
