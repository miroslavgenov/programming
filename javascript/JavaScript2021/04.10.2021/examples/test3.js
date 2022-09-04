function hello() {
    console.log("hello")
}

hello.call()
hello.apply()
hello()
hello = hello()


function test() {
    console.log(arguments)
    console.log(this)
}

console.log(test(66, 66))
test(1, 2, 3, 4, 5, 6, 7)
test()

function test1(a, b) {
    console.log("here!!")
    console.log(arguments)
    console.log(typeof arguments)
    console.log(this)
    console.log(typeof arguments)
    return a + b
}


console.log(test1(1, 1))

test(1, 2)

