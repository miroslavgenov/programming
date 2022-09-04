function hello(){
    console.log(this);
    console.log(arguments);
    
    for(let i=0;i<arguments.length;i++){
        console.log(arguments[i]);
    }
    
}

hello(1,2,3,4,5,6,7,"h");
