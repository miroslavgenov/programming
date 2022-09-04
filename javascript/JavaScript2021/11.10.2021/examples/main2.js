var person = { myName: "Ivan" }
console.log(person)
console.log(person.myName)

console.log(person['myName'] == 'Ivan')
console.log(person.myName == 'Ivan')

var randomName = person.myName == 'Ivan' ? randomName = '1' : randomName = '2';
console.log(randomName)


person.myName = person.myName == 'Ivan' ? person.myName = '1' : person.myName = '2';
console.log(person.myName)








