// functio retuning function
function a() {
    console.log('a');
    return function () {
        console.log('b')
    }
}

a();
a()();