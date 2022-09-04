// vlojeni obekti

var person = {
    age: 20,
    child: {
        age: 15
    }
}

console.log(person.child.age)
console.log(person['child'].age)
console.log(person.child['age'])
console.log(person['child']['age'])




