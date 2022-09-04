// Suzdavane na regulqren izraz

// iteration
// all string contains this in
var reg = /hello/;
console.log(reg.test("my name is hello"));
// $ if string ends with s will be true
var reg1 = /s$/;
// true
console.log(reg1.test("this is"));
// false
console.log(reg1.test("this i"));
// true
console.log(reg1.test("this"));
// ^ if the string starts with s
var reg2 = /^s/;
console.log(reg2.test("sister"));
