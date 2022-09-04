var person = {
    name: 'ivan',
    age: 15,
    'city': 'Burgas',
    show: function () { console.log("= ", this.name, this.age); }
};

person.show();

var person1 = ['ivan', 's']

// person.forEach(element => { console.log(element) })

for (i in person) {
    console.log(person[i])
}

for (i of person1) {
    console.log(i)
}



