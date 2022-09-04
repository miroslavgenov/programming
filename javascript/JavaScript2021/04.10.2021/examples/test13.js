var number = 10;
var array = [10, 'ivan', true];

//this is object
var obj = { name: 'ivan', age: 19 };

console.log(obj.age)
console.log(obj.name)

var obj1 = { name: "Alex", age: 17, message: function () { console.log("Hello i am ", this.name); } }

obj1.message();