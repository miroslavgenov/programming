//function expresion

// say('hello world'); //error


var say = function (message) { return message; };

var array = [1, 2, 3, say, 4, 5, 6];
var b = array[3];

console.log(array);
console.log(b('hello world'));
console.log(array[3]('this is interesting'));