
var a = function () {
    return {
        sum: function (x, y) { return x + y },
        mult: function (x, y) { return x * y },
        div: function (x, y) { return x / y }
    }
}()

console.log(a.sum(1, 2))
console.log(a.mult(2, 2))
console.log(a.div(2, 2))