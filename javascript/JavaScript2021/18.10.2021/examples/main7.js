// ? equals 0 or 1 times
// b zero or b 1 times
var reg = /ab?c/;
console.log(reg.test("ac"));
console.log(reg.test("abc"));
console.log(reg.test("bcac"));
console.log(reg.test("bcabc"));
console.log(reg.test("ab"));
console.log(reg.test("bc"));
console.log(reg.test("ab"));
