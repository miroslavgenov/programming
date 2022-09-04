//A
var string = "софия пловдив варна бургас плевен";
var array = string.split(" ");
//A

//B
var arrayFirstCharUpperCase = [];

//before
// for (x of array) {
// console.log(x.replace(x[0], x[0].toUpperCase()))
// arrayFirstCharUpperCase.push(x.replace(x[0], x[0].toUpperCase()));
// }

//edited
array.forEach(element =>
    arrayFirstCharUpperCase.push(element.replace(element[0], element[0].toUpperCase()))
);


console.log(...arrayFirstCharUpperCase);
//B

//C
var count = 0;
// for (x of arrayFirstCharUpperCase) {
//     if (x.indexOf("а") > -1) {
//         count++;
//     }
// }


arrayFirstCharUpperCase.forEach(element => {
    if (element.indexOf('а') > -1) { count++ };
})
console.log(count.toString() + " cities contains letter 'a'.");
//C

//D

var newCities = "";

// for (x of arrayFirstCharUpperCase) {
// newCities += x;
// }

arrayFirstCharUpperCase.forEach(element => newCities += element)
console.log(newCities);

var citiesChars = newCities.split('');
console.log(citiesChars);
//D
