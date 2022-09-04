var setGrace = function () {
    var numbs = Array.from(arguments);

    this.grade = Math.floor(numbs.reduce(function (a, b) { return a + b; }, 0) / numbs.length);

}

var std = { grade: 2 };
console.log(std);

setGrace.apply(std, [10, 10, 10, 10]);
console.log(std);

