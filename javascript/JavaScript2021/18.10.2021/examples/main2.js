var reg = /^[a-z]/;
console.log(reg.test("1"));
console.log(reg.test("A"));
console.log(reg.test("b"));

console.log();
//tova e za otricanie kogato e vutre v [^a-z]
reg = /^[^A-Z]/;
console.log(reg.test("1"));
console.log(reg.test("A"));
console.log(reg.test("b"));

console.log();
reg = /[A-Za-z]/;
console.log(reg.test("He"));

console.log();
reg = /[A-Z]/;
console.log(reg.test("He"));

console.log();
console.log(/[a-z]/i.test("HELLO WORLD"));
