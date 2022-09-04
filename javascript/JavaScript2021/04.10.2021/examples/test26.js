function mul(a, b, c, callback) {
    var arr = Array.from(arguments);
    var arr1 = [];

    for (let i = 0; i < arr.length - 2; i++) {
        arr1[i] = arr[arr.length - 1](arr[i])
    }
    return arr1
}

function addOne(a) {
    return a + 1;
}


console.log(mul(1, 2, 3, addOne));
// mul(1, 2, 3, addOne);



