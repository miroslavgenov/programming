// Дата е записана във формат "2017-09-21 "​
//A) Запишете я във формат "21.09.2017 "​
//B) Отделете годината от датата

//A
var date = "2017-09-21";

//before
// var dateDigits = date.split('-');
// var newDate = "";
// var len = dateDigits.length;

// for (i = len - 1; i >= 0; i--) {
//     newDate += dateDigits[i];
//     if (i > 0) {
//         //za da ne se sloji  '.' na kraq sled 2017
//         newDate += '.';
//     }
// }
// console.log(newDate);

//edited
date = date.split('-').reverse().join('.');
console.log(date)

//A

//B
//before
// var yearNext = 0;
// var dateSplit = "";
// var yearSplit = "";
// for (x of newDate) {


//     if (x == '.') {
//         yearNext++;
//     }

//     // console.log(x)
//     if (yearNext == 0) {
//         dateSplit += x;

//     }
//     else if (yearNext == 1) {
//         dateSplit += x;
//     }
//     else if (yearNext == 2) {
//         if (x != '.') {
//             yearSplit += x;
//         }
//     }
// 
// }

//edited
var dateSplit = date.slice(0, date.length - 5);
var yearSplit = date.slice(-4);
//B


console.log("Date: ", dateSplit);
console.log("Year: ", yearSplit);

