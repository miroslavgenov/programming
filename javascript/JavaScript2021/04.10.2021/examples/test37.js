var a = 'global';
var f = function () {
    var b = 'local';
    var n = function () {
        var c = 'inner local';
        return b;
    }
    return n;
}

console.log(f);
console.log(f());
console.log(f()());
