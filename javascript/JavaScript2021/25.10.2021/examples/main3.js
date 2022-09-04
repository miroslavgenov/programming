function hello() {
  this.alert("hello world !");
  this.confirm("hello world ?");
  //error
  // this.input();
}
hello();
