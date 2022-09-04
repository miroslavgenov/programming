var f = document.myform;
var ta = f.ta;

ta.addEventListener("dblclick", (e) => {
  var reg = /\S+/g;
  var test;
  var count = 0;
  while ((test = reg.exec(ta.value)) != null) {
    count++;
  }
  console.log(count);

  var tatxt = ta.value;
  console.log(tatxt.match(/\S+/g));
  var arr = tatxt.match(/\S+/g);
  console.log(arr.length);
});
