//suzdava ne na functioq  a constructora sochi kym funkciqta

function mFun() { }

mFun.prototype = { constructor: mFun };

var obj = new mFun();


// obj.constructor e ekvivalentno na obj.__proto__.constructor
obj.constructor;
obj.__proto__.constructor;

