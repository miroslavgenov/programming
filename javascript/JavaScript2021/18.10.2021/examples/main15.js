// eny character except new line
reg = /./;
console.log(reg.test("*"));
console.log();
reg = /\w/; //[a-zA-Z0-9_]
console.log(reg.test("_"));
console.log();

reg = /\W/; //// otricanite na [^a-zA-Z0-9]
console.log(reg.test("%"));
console.log();

reg = /\s/; //- eny white space character [\t\n\r\f\v ]
console.log(reg.test(" "));
console.log();

reg = /\S/; //- negative white space character [\t\n\r\f\v ]
console.log(reg.test("x"));
console.log();

reg = /\d/; //digit [0-9]
console.log(reg.test("9"));
console.log();

reg = /\D/; // [^0-9]
console.log(reg.test("x"));
console.log();

reg = /\b/; //a word bounduri between w and W
console.log("??");
console.log(reg.test("")); //??
reg = /\B/; // a word not boundary
// ??
console.log("??");
console.log(reg.test("")); //??
reg = /[\b]/; //bakc space
