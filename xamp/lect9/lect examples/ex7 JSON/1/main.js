var xhr = new XMLHttpRequest();

xhr.open("GET", "student.json");
xhr.addEventListener("load", readJSON);
xhr.send();

function readJSON() {
  if (this.status == 200) {
    console.log(this.responseText);
    var students = JSON.parse(this.responseText);
    console.log(students);

    var studentsJS = JSON.stringify(students);
    console.log(studentsJS);
  }
}
