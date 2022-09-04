var message = "Hello world";
(function (string) { console.log(string) })(message);

var person = { 'blablaName': 'Vasil' }, num = 1;
console.log(person.blablaName);
console.log();
(function (obj) { obj.blablaName = "Lili" })(person);
console.log(person);

(function (number) {
    var num = 100;
    number = 100;
    console.log("This num", num);
    console.log(number);
})(num);
console.log(num);
