var sumObj = {
    name: 'sum',
    sum: function (a, b) {
        console.log(arguments);
        console.log(this);
        console.log(this.name);
        console.log(a + b);
    }
}

console.log(sumObj);
sumObj.sum(1, 1);
console.log(typeof sumObj);



console.log(Object.getOwnPropertyNames(Object.prototype));


console.log(sumObj.valueOf());

