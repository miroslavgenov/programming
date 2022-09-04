// special symbols
// ^ for beggining
// [^] for inversion
// $ for end

console.log(/[a-z]$/.test("1s1a"));
console.log(/^[A-Z$]/.test("A$"));
console.log(/^[A-Z$]/.test("x$"));
