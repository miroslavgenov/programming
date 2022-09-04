// potrebitelski obekti

function Dog(name, breed, weight) {
    this.name = name;
    this.breed = breed;
    this.weight = weight;
    this.bark = function () {
        if (this.weight > 25) {
            console.log('bark');
        } else {
            console.log('yip')
        }
    }
    
};

var dog1 = new Dog('alex', 'mix', 30);
dog1.bark();
console.log(dog1.name)

console.log(Dog.constructor)

