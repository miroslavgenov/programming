//closure v loop

function f() {
    var arr = [], i;
    for (i = 0; i < 3; i++) {
        arr[i] = function (x) {
            return function () {
                return x;
            };
        }(i)
    }
    return arr;
}

var x = f();
console.log(x);
console.log(x[0]())
console.log(x[1]())
console.log(x[2]())
