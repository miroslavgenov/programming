function outer() {

    function inner() {
        return 1 + 1;
    }

    return `The result is ${inner()}`;
    //return 'The result is: '+inner();
}

console.log(outer())


function out1(param) {

    function inner(x) {
        return x + x;
    }

    return 'result is ' + inner(param);
}

console.log(out1(2));

