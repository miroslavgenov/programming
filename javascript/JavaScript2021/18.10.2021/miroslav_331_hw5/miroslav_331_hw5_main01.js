//1.  Напишете регулярен израз,
//който проверява факултетен номер на студент:
//факултетният номер следва да започва с 1-4 главни букви на кирилица,
// следван от 0 и повече интервали и да завършва с от 1
//до 4 цифри.

console.log("Exercise 1");

var reg = /^[А-Я]{1,4} *\d{1,4}$/;

//print regexp
console.log("RegExp: ", reg);

console.log('reg.test("КККК1234")');

// test KST 1234
console.log(reg.test("КСТ 1234"));

console.log('reg.test("СИ 12")');

// test SI 12
console.log(reg.test("СИ 12"));

console.log('reg.test("13")');
// test false condition
console.log(reg.test("13"));

console.log("end Exercise 1");
console.log();
