function mBT(a, b, c, callback) {
    var ar = [];

    for (let i = 0; i < 3; i++) {
        ar[i] = callback(arguments[i] * 2);
    }
    return ar;
}

function add1(a) { return 1 + a; }


console.log(mBT(1, 2, 3, add1))
