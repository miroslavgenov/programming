// 3. Напишете функция makeList(), която получава като параметър името на студентска група,
//  например KСТ-11 и го  съхранява като начално значение на променливата list,
//  декларирана в тялото й.  makeList() връща функция аddName,
// която получава като параметът име на студент ,
//  конкатенира  го с текущото значение на променливата list u uзвежда list в конзолата 
//(като резултат след всяко извикване на  върнатата функция трябва да виждаме обновения списък с имена).


function makeList(groupName) {
    var list = [];
    list.push(groupName)
    var charSpace = ' ';


    return {
        addName: function (sName) {
            list.push(sName);
            console.log(list[0].concat(charSpace, sName));
            return list.slice(1);
        }


    };
}

var x = makeList('KST-11')
x.addName('Ivan');
x.addName('Boris');
console.log(x.addName('Alex'));

// console.log(makeList('kst')('Ivan'));


