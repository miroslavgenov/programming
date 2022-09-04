class Person {
  constructor(_name, _phone) {
    this.name = _name;
    this.phone = _phone;
  } // constructor
  Show() {
    document.write(`${this.name} има телефон ${this.phone}<br>`);
  } // Show
} // Person

//   let persons = [new Person('Ани Радева', '0889123456'), new Person('Филип Тончев', '0897123456')];
//   persons.forEach( e => e.Show() );

class Student extends Person {
  constructor(_name, _phone, _specialty, _grade) {
    super(_name, _phone);
    this.specialty = _specialty;
    this.grade = _grade;
  } // constructor
  Show() {
    document.write("<p>Студент:<br>");
    super.Show();
    document.write(`специалност: ${this.specialty}, ${this.grade}`);
    document.write("</p>");
  } // Show
} // Student

class Lecturer extends Person {
  constructor(_name, _phone, _title, _salary) {
    super(_name, _phone);
    this.title = _title;
    this.salary = _salary;
  } // constructor
  Show() {
    document.write("<p>преподавател:<br>");
    super.Show();
    document.write(`степен: ${this.title}, заплата: ${this.salary}`);
    document.write("</p>");
  } // Show
} // Lecturer

let students = [
  new Student("Стела Петрова", "0879123456", "КСТ", 4.25),
  new Student("Ивайло Кирилов", "0888123456", "Философия", 6),
];
let lecturers = [
  new Lecturer("Владимиров", "0898123456", "Д-р", 1300),
  new Lecturer("Янева", "0874123456", "ДМН", 2100),
];

students.forEach((s) => s.Show());
lecturers.forEach((l) => l.Show());

let a = lecturers.reduce((amount, l) => {
  amount += l.salary;
  return amount;
}, 0);
document.write(`средна заплата: ${a / lecturers.length}<br>`);

let hg = students.reduce((hgs, cs) => {
  if (cs.grade > hgs.grade) hgs = cs;
  return hgs;
});
document.write("<p>най-висок успех:<br>");
hg.Show();

// самостоятелна работа:

let people = [
  new Student("Стела Петрова", "0879123456", "КСТ", 4.25),
  new Student("Ивайло Кирилов", "0888123456", "Философия", 6),
  new Lecturer("Владимиров", "0898123456", "Д-р", 1300),
  new Lecturer("Янева", "0874123456", "ДМН", 2100),
];
// опитайте да извлечете в отделни масиви студентите и преподавателите от масива people.
// Ако е необходимо добавете свойство в класа Person.

// Решение от Мирослав 331 СИ 13
// този масив studendsOnly ще съхранява студенти
var studendsOnly = [];
// този масив lecturersOnly ще съхранява преподаватели
var lecturersOnly = [];

// фор цикъл обхожда масив people
people.forEach((p) => {
  // ако елемен p е инстанция от Student
  // ще го запише във studendsOnly
  if (p instanceof Student) {
    studendsOnly.push(p);
  } //if
  //// ако елемен p е инстанция от Lecturer
  // ще го запише във studendslecturersOnlyOnly
  else if (p instanceof Lecturer) {
    lecturersOnly.push(p);
  } //else if
}); //people.forEach

// динамично създаване на h1
var h1 = document.createElement("h1");
h1.innerText = "Само студенти";
document.body.appendChild(h1);

//показване на студентите
studendsOnly.forEach((so) => so.Show());

// клониране на h1
var h1_close = h1.cloneNode(true);
h1_close.innerText = "Само преподаватели";
document.body.appendChild(h1_close);

//показване на преподаватели
lecturersOnly.forEach((lo) => lo.Show());
