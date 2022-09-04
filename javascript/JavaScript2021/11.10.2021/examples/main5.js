// dobavqne i iztrivane na svoistva

var person = { name: 'Ivan', 'home city': 'Burgas', age: 10 };

person['eat'] = '123';
person.eat1 = 'diner';
console.log(person)

delete person.name;
console.log(person)
delete person['home city'];
delete person['eat'];
delete person['eat1'];
console.log(person)

console.log('eat' in person)

for (i in person) { console.log(i, person[i]) }





