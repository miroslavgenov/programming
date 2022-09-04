function Msg() { }

Msg.prototype = {
    constructor: Msg,
    includes: function () {
        console.log('123')
    }
}

//starata function po gore e zamenena s novata function
//dobavqne na metodi
Msg.prototype.includes = function () { console.log('hello world'); };

var x = new Msg();

x.includes()


