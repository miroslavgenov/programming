function MyStudent(name, marks) {
    this.name = name;
    this.marks = [];

    for (i = 1; i < arguments.length; i++) {
        this.marks[i - 1] = arguments[i];
    }
}

MyStudent.prototype.aveMark = function () {
    return this.marks.reduce(function (s, x) { return s + x; }) / this.marks.length;
}


var s1 = new MyStudent('Petq', 3, 4, 5);

console.log(s1);

console.log(s1.aveMark());


