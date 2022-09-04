function multyByTwo(a, b, c, callback) {
    var array = Array.prototype.slice.call(arguments);

    array.forEach(element => {
        console.log(element)
    });

    array = Array.from(arguments);
    console.log(array)

}


multyByTwo(1, 2, 3, 4)


