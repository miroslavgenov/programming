//2. Напишете регулярен израз,
//съвпадение с който дават дати, написани във вида:
//      29.12.2017 г.
//      29-12-2017 г.
//(цифрата в деня и месеца може да е  една:  1.3.2018 г.  или 01.03.2018 г.   )

console.log("Exercise 2");

console.log(
  "var reg = /^[012]{0,1}[0-9][\\.-][01]{0,1}[0-9][\\.-][0-9]{4} г\\.$/;"
);

var reg = /^[012]{0,1}[0-9][\.-][01]{0,1}[0-9][\.-][0-9]{4} г\.$/;

console.log(reg.test("13.12.1234 г."));
console.log(reg.test("29.12.2017 г."));
console.log(reg.test("29-12-2017 г."));
console.log(reg.test("1.3.2018 г."));
console.log(reg.test("01.03.2018 г."));

console.log("end Exercise 2");
console.log();
