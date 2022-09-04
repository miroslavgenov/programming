// 1. Напишете функция process(arr, f) където arr e аргумент-масив,
// а f() e callback функция, очакваща параметър масив.
// process() връща  резултата от приложената към масива функция f(). ​

// Направете 2 извиквания на process() с използване на различни функции f() -  например:​
//  (1) - с  функция, изчисляваща сумата  на елементите на масива-параметър​
//  (2) - с функция, връщаща  нов масив с увеличени  с 1 елементи. ​

console.log("Zadacha 1");

//(1)
function sumArray(myArray) {
  console.log("sumArray(myArray)");
  return myArray.reduce((num1, num2) => num1 + num2);
}
//(2)
function mapArray(myArray) {
  console.log("mapArray(myArray)");
  return myArray.map((x) => x + 1);
}

//1.
function process(f) {
  console.log("process(f)");
  return f;
}

//test
var numArr = [1, 2, 3];
var funcArr = [sumArray, mapArray];

funcArr.forEach((element) => {
  console.log(process(element(numArr)));
});
