//var scope

function hello() {

    let var1 = "hello1"
    var4 = "hello4"

    {
        let var2 = "hello2"
        var var3 = "hello3"
        console.log(var4)
    }
    console.log(var4) // no error
    console.log(var1) //no error
    console.log(var2) // error
    console.log(var3) // no error
}

// console.log(var4) // error
// hello() // un comment this 

//var scope end


// null and undefined
console.log()

console.log("hello world")

console.log("result=" + 3)

my_var = undefined
my_var1 = undefined

console.log(typeof (my_var))
console.log(my_var == my_var1)

my_var = null // will make my_var object
console.log(my_var == my_var1)
console.log(typeof (my_var))

//null and undefined

//integer

var number = 1
number++
console.log(number)
console.log("hello " + number)
number--
console.log(number)

// string test
my_var = "ivan"
my_var1 = "ivan"

console.log(my_var === my_var1)

// make reference
my_var = new String("Ivan")
my_var1 = new String("Ivan")
console.log(my_var === my_var1)

// obvivki
my_var = String("Ivan")
my_var1 = String("Ivan")
console.log(my_var === my_var1)
console.log(typeof (my_var))
console.log(typeof (my_var1))
// obvivki

// object
my_var = new String("Ivan")
my_var1 = new String("Ivan")
console.log(my_var === my_var1)
console.log(typeof (my_var))
console.log(typeof (my_var1))
// object

//types
my_var2 = true
my_var3 = false
my_var = 1.2
my_var1 = 'h'

console.log(my_var)
console.log(my_var1)
console.log(my_var2)
console.log(my_var3)

console.log(typeof (my_var))
console.log(typeof (my_var1))
console.log(typeof (my_var2))
console.log(typeof (my_var3))
//types

// toLowerCase and toUpperCase
var name = "Ivan Georgiev Ivanov"
console.log(name)
console.log(name.toUpperCase())
console.log(name.toLowerCase())
console.log(name.length)

var chars = name.length

var smallName = name.toLowerCase()
console.log(smallName)
console.log(name)
//charAt(index) -return the char at this index , 
// name[] , 
// indexOf(start[,end]) - search in the string
console.log(name.charAt(2)) // return tha char at pos 2
console.log(name[3]) // return the char at pos 3

console.log(name)
console.log(name.indexOf('I'))

//slice start index [, end index]

var space1 = name.indexOf(' ')
console.log(space1)
var first_name = name.slice(0, space1)
console.log(first_name)

console.log(name)
var space2 = name.indexOf(" ", space1 + 1)
console.log(space2)
var third_name = name.slice(space2 + 1)
console.log(third_name)

// last name
var last = chars - space2 - 1
console.log(name.slice(-last))

// only last name and the first 3 chars
console.log(name.slice(-last, -3))

console.log(name.substring(5, 12 + 1)) // vzima ot celiq string 
console.log(name.substr(5, 8)) // vzima ot 5 i kolko e dulgo Georgiev v slychaq 8

console.log(name.replace(' Georgiev Ivanov', ' ')) // serch this Georgiev Ivanov and will replace it with ' '
var my_new_name = name.replace(" Georgiev Ivanov", ' ')
console.log(my_new_name)

console.log(my_new_name.startsWith('v', 1))
console.log(my_new_name.startsWith('I'))

console.log(my_new_name.endsWith('a', 1))
console.log(my_new_name.endsWith('n', 4))

// preobrazyvane na nij v masiv

console.log(name)
var name_split = name.split(' ') // will split the white space
console.log(name_split)

var char_split = name.split('')
console.log(char_split)
