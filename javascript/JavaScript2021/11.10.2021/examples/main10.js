// suzdavane na obekti s object create

var ob1 = Object.create({ x: 1, y: 2 });
console.log(ob1.x);
console.log(ob1.y);
console.log();

var ob2 = Object.create(null);

//analogichno na var x= new Object();
var ob3 = Object.create(Object.prototype);
console.log(ob3.constructor);