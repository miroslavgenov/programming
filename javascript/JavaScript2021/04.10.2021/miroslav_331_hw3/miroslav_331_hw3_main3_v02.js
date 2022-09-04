// 3. Напишете функция makeList(), която получава като параметър името на студентска група,
//  например KСТ-11 и го  съхранява като начално значение на променливата list,
//  декларирана в тялото й.  makeList() връща функция аddName,
// която получава като параметът име на студент ,
//  конкатенира  го с текущото значение на променливата list u uзвежда list в конзолата
//(като резултат след всяко извикване на  върнатата функция трябва да виждаме обновения списък с имена).

console.log("Zadacha 3");

function makeList(studentGroupName) {
  var list = [];
  list.push(studentGroupName);

  function addName(studentName) {
    list.push(studentName);
    return list.join(" ");
  }

  return addName;
}

var list = makeList("KST-11");

list("Ivan");
list("Alex");
list("Chocho");
console.log(list());
list("Misho");
list("Gabo");
console.log(list());
