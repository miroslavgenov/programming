// second version closure loop
function f() {
    function binder(x) {
        return () => x;
    };


    var arr = [], i;
    for (i, 0; i < 3; i++) {
        arr[i] = binder(i);
    }
    return arr;
}