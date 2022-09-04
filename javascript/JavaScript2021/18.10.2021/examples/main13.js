//comma characters

reg = /ab..b/;
console.log(reg.test("ab__b"));
console.log(reg.test("ab_&b"));
console.log(reg.test("ab12b"));
console.log(reg.test("abssb"));
