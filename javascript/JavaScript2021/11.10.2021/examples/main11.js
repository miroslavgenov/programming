function Range(name, message) {
    this.name = name;
    this.message = message;
}

Range.prototype = {
    greethings: function () {
        console.log(this.message, this.name);
    },
    foreach: function () {
        for (i = 0; i < 4; i++) {
            console.log(this.name);
        }
    }
};


var test = new Range('ivo', 'hello');
test.greethings();
test.foreach();



