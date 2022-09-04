var Dog = function (a, b) {
    this.bread = a;
    this.age = b;
};

var dog1 = new Dog('hello', 2);

console.log(dog1);
console.dir(dog1);
console.log(typeof dog1);

var dog2 = new Dog;
dog2.bread = 'I';
dog2.age = '1';
console.dir(dog2);
