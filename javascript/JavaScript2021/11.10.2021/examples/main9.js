var Student = function (fn, g) {
    this.fn = fn;
    this.g = g;
};


var Alex = new Student('kst 11', 15);
console.log(Alex.constructor)

// suzdavane na analogichen obekt

var Dimo = new Alex.constructor('kst 12', 16);
console.log(Dimo.constructor)
console.log(Dimo)


