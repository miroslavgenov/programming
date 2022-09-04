//closures  ima obhvat i funkciite se izpulnqvat v 
//obhata v koito sa definirani


var scope = 'global';
function checkscope() {

    var scope = 'local soce';

    function f() { return scope; }
    return f();
}

console.log(checkscope());

