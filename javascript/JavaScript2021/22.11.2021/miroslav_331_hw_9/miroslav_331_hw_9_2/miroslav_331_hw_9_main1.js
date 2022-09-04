// GET DATABASE
var btn2 = document.getElementById("btn2");
var xhr = new XMLHttpRequest();
xhr.open("GET", "miroslav_331_hw_9_index1.php");

xhr.addEventListener("load", hello);
function hello() {
  if (xhr.status == 200) {
    var data = JSON.parse(xhr.responseText);
    data.forEach((element) => {
      let p = document.createElement("p");
      p.innerText = element.title + " " + element.likes;
      document.body.appendChild(p);
    });
  }
}

btn2.addEventListener("click", () => {
  xhr.send();

  getData("miroslav_331_hw_9_index1.php");
});

async function getData(url) {
  var bigdata = await fetch(url, {
    method: "GET",
    headers: { "Content-type": "application/json" },
  });
  // show the
  console.log(await bigdata.json());
}
