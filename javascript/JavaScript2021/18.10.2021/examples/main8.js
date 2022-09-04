// Repetitions specifiers
// /x{1,10}/ -letter x repeats between 1 times to 10 times
// /x{10}/ - exaclty 10 times
reg = /x{2,10}/;
console.log(reg.test("xxxxxxxxxx"));
//because contains 10 times return true even if there more
console.log(reg.test("xxxxxxxxxxxxxx"));
console.log(reg.test("x"));

console.log();
// reg = /xxxx/
reg = /x{4}/;
console.log(reg.test("x"));
console.log(reg.test("xxxx"));
// if there 4 'x' return true
console.log(reg.test("xxxxxx"));
