//function declaration
function func() {
    console.log('hello');
}
//

var g = func;
func = null;
console.log(func);
g();


