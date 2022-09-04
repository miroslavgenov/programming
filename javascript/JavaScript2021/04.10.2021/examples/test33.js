//samoizvikvashi se funkcii
(function (x) { console.log(x) }('i'));
(function (x) { console.log(x) })('x');

var a = function () { console.log('!!!') }()


var a = (function () { console.log('p') })()

var a = (function () {
    function setUp() {
        console.log('set up');
    }
    function work() {
        console.log('work');
    }
    setUp();
    return work; // refernciq kum funkciq
})();
a();
// a;