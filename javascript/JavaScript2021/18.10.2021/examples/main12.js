//otricanie
var reg = /[^,]+(,[^,]+)/;
console.log(reg.test("ivan,ivan"));
var reg = /[^,]+(,[^,]+){4}/;
console.log(reg.test("ivan,ivan,ivan,ivan"));
console.log(reg.test("ivan, ivan, ivan, ivan"));
