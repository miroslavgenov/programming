var age = 20;

var message;

if (age >= 18) {
    message = function () { console.log("Hello you are >=18"); };
} else {
    message = function () { console.log("Hello you are <") };
}

message();