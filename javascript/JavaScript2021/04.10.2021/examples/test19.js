var calc = function () {
    var gradesArg = Array.prototype.slice.call(arguments);

    this.grade = Math.floor(gradesArg.reduce(function (a, b) { return a + b }, 0) / gradesArg.length);
}

var myStudent = { grade: 1 };
console.log()
console.log(myStudent);
calc.apply(myStudent, [6, 6, 6, 6])
console.log(myStudent);

