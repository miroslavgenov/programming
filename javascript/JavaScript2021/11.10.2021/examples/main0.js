var a = { age: 10 };
var b = a;
console.log(a, b)

b.age = 15;
a.age = 20;

console.log(a, b)