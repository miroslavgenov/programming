// za sega ne raboti
var inner; // глобална променлива​

var F = function () {

    var b = "local variable";

    var N = function () {

        var c = "inner local";

        return b;

    };

    inner = N;

};

inner();