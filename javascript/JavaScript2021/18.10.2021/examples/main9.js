// {3,} -- minimum 3 sumbols ;
reg = /ab{3,}c/;
console.log(reg.test("ac"));
console.log(reg.test("abc"));
console.log(reg.test("abbbc"));
console.log(reg.test("abbbbbbbbbx"));
console.log(reg.test("abbbbbbbbbxc"));
console.log(reg.test("abbbbbbbbbc"));
