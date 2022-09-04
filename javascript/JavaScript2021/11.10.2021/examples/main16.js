class myNumber {
    constructor(name, number) {
        this.name = name;
        this.number = number;
    }
}

var list = [
    new myNumber("a", 4),
    new myNumber("b", 4),
    new myNumber("c", 4),
    new myNumber("d", 4)
];

var sum = list.reduce((x, y) => x + y.number, 0) / list.length;

console.log(list);
console.log(sum);


