reg = /beautiful ([a-zA-z]+) (\(\d+\))/gi;

string = "beautiful xxxx (1234),beautiful ksda (2003)";
console.log(reg.exec(string));

var test;
while ((test = reg.exec(string)) != null) {
  console.log(test[0]);
  console.log(test[1]);
  console.log(test[2]);
}
