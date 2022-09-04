function hello(){
    let text="Hello";
    function msg(param){
        console.log(text,param);
    }
    return msg;
}

var x=Math.PI;
console.log(x);

var x=hello();
x("hello!");