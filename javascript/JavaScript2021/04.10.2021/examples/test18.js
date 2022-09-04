var refresh = function (a, b) {
    this.course = a;
    this.grade = b;
}

var student = { name: 'ivan', field: 'kst', course: 3, grade: 6 };

console.log(student);

refresh.call(student, 99, 99)

console.log(student);
refresh.apply(student, [0, 0])
console.log(student);