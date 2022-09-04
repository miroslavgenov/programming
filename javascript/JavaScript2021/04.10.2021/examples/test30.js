var result = function () {
    console.log(arguments)
    console.log(this)
}


result(1, 2, 3)

// funkiite strelki nqmat arguments i this , i te sa annonimni
var result1 = () => { console.log(arguments); console.log(this) };
result1(6, 6, 6, 6)


//ako parametarut e 1 skobite sa ne zaduljitelni
// ako nqma parametur skobite sa zaduljitelni

var result2 = x => console.log(x);
result2(333)
var result3 = () => console.log('hi');




