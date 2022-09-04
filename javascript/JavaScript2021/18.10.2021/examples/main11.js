// Class sumbols
// [pbm]ill   - will search if p or b or m  -> pill , bill , mill not pbmill

reg = /[pbm]ill/;
console.log(reg.test("a"));
console.log(reg.test("aill"));
console.log(reg.test("bill"));

console.log();
reg = /[1234567890]/;
console.log(reg.test("2"));
console.log();
reg = /[1234567890]/;
console.log(reg.test("x"));
console.log();
reg = /[0-9]/;
console.log(reg.test("x"));
console.log();
reg = /[0-9]/;
console.log(reg.test("2"));
console.log();

reg=/[a-zA-Z0-9]/
console.log(reg.test("@"));
console.log(reg.test("a"));
console.log(reg.test("A"));
console.log(reg.test("0"));
