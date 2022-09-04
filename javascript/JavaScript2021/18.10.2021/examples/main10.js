// grouping ()

reg = /(ab){2} c/;
console.log(reg.test("abab c"));
console.log(reg.test("ab ab c"));
console.log();
reg = /ab{2} c/;
console.log(reg.test("abb c"));

// will have 3 spaces
reg = /(very) {3} hot/;
console.log(reg.test("very   hot"));
console.log(reg.test("very very very  hot"));
reg = /(very ){3}hot/;
console.log(reg.test("very very very hot"));
