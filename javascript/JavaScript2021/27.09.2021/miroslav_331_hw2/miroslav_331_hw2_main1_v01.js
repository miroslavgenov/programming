// Tazi zadcha sudurja 2 yslaviq 1-vo i 3-to
// Създайте числов масив от случайни елементи в диапазона 1-10  и
// определете нов масив, съдържащ  третите степени на елементите на изходния масив

var randomNums = [];
randomNums.length = 15;
randomNums.fill(0);

//after
randomNums = randomNums.map(
  (el) => (el = Math.floor(Number(Math.random() * 10 + 1)))
);

var power3Nums = randomNums.map((el) => el * el * el);

console.log(`Arr  random numbers:\n${randomNums}`);
console.log(`Arr power of 3 nums:\n${power3Nums}`);

// За масива от пример 1 определете произведението и сумата от
// квадратите на елементите ( използвайте reduce)​
var sumMultipl = randomNums.reduce((x, y) => x * y, 1);
var sumSqrt = randomNums.reduce((x, y) => x + Math.sqrt(y), 0);

console.log(`multiplication result = ${sumMultipl}`);
console.log(`sqrtResult=  ${sumSqrt}`);
