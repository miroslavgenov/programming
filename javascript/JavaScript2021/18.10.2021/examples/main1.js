// using options modifiers
// /myRexExpres/i , /myRexExpres/g , /myRexExpres/m
// /myRexExpres/i/g , /myRexExpres/g/m , /myRexExpres/m/i ...
// new RegExp("hello",i) , new RegExp("hello",i,g) ...
// i - ignors the difference between lower and upper letters
// g- serching for all coincidents in the string /hello/.match("hi hello how are you hello")
// m - check multy lines and if only one line is true then return false

var reg1 = /hello/i;
console.log(reg1.test("HELLO "));
reg1 = /hello/g;
console.log("hello how are you hello".match(reg1));
reg1 = /^h/m;
console.log(reg1.test("hello\nhow"));
console.log(reg1.test("ello\nhnow"));
console.log(reg1.test("1ello\n1now"));
