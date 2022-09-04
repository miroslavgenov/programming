getData("student.json").then((val) => console.log(val));
async function getData(url) {
  var res = await fetch(url);
  return await res.json();
}
