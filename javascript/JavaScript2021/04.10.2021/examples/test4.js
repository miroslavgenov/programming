function sum(a, b) {

    var c = a + b;
    return c;
}

function showArguments() {
    return arguments
}

var res = sum(1);
console.log(res)
res = sum(1, 2, 3, 4, 5, 6, 7, 8, 9);
console.log(res)


var arg = showArguments("Ivan", 1.6, true)
console.log(arg)

