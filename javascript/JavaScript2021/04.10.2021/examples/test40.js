var c = function () {
    var n = 0;
    return {
        count: function () { return n++; },
        reset: function () { n = 0; }
    }
}();

console.log(c.count())
console.log(c.count())
c.reset();
console.log(c.count())
