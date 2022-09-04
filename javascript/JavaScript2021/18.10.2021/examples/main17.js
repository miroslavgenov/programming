// sub expresions using grouping

var reg = /\w+ \w+ [\d-]{9}/;
var myName = "Ivan Boris 07-532-32";

console.log(reg.test("Ivan Boris 123-45-6789"));
reg = /(\w+) \w+ ([\d-]{9})/;
if (reg.test(myName)) {
  console.log("name", RegExp.$1);
  console.log("Name", RegExp.$2);
}
