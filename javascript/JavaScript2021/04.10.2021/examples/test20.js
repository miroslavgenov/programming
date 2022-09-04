// suzdavane na masiv ot masivopodobni elementi
function hello() {
    var arr = Array.from(arguments);
    console.log(arr);
}

hello([1, 2, 3, 4]);
hello(1, 2, 3, 4);
