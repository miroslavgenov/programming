function sumArg() {
    sumNumber = 0;
    for (i = 0; i < arguments.length; i++) {
        console.log(arguments[i]);
        sumNumber += arguments[i];

    }
    console.log()
    return sumNumber;
}

console.log(sumArg(1, 2, 3));