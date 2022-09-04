// functions working with regular expresions

//test() return true or false if regExp match
console.log(/a$/.test("A b A c a"));
//exec() return array with the index of the first match
//null if no matsh
// output [ 'hi', index: 0, input: 'hi how are you .hi', groups: undefined ]
console.log(/hi/.exec("hi how are you .hi"));
console.log(/0/.exec("hi how are you .hi"));
//search() return the position of the first match return -1 if no match
// applies for string objects
console.log("hello worlod".search(/lo/));
console.log("hello worlod".search(/1/));

//match() equal to exec but for strings
console.log();
console.log("your name iv ivan".match(new RegExp("iv", "g")));
console.log("your name iv ivan".match(/iv/));
console.log("your name iv ivan".match(/x/));

//replace()
console.log("mynamemy".replace(/my/, ""));

//split()
console.log("youawesomeyou".split(/you/));
