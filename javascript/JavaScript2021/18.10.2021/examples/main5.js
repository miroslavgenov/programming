//[ab*c] equals 0 times or more times
// b 0 times or more times
var reg = /ab*c/;
console.log(reg.test("a"));
console.log(reg.test("aa"));
console.log(reg.test("aabb"));
console.log("->", reg.test("ab"));
console.log(reg.test("acc"));
console.log(reg.test("ac"));
console.log("-->", reg.test("c"));
console.log(reg.test("ca"));
console.log(reg.test("bc"));
console.log(reg.test("bc"));
console.log(reg.test("ac"));
console.log(reg.test("abbbbbbbbc"));
console.log(reg.test("bc"));
console.log();
