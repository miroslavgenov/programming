//[ab+c] equals 1 times or more times
// b 1 time or more times
reg = /ab+c/;
console.log(reg.test("ab"));
console.log(reg.test("abc"));
console.log(reg.test("abcc"));
console.log(reg.test("acc"));
console.log(reg.test("bcc"));
console.log(reg.test("ab"));
console.log(reg.test("abbc"));
console.log(reg.test("ababc"));
console.log(reg.test("abacbc"));
