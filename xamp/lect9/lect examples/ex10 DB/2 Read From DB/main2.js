var form1 = document.getElementById("form1");
var input1 = document.getElementById("input1");

form1.addEventListener("submit", (e) => {
  e.preventDefault();
  var values = async function () {
    fetch("readDb.php", {
      method: "POST",
      headers: { "Content-type": "application/json" },
    });
    console.log(await fetch.json());
  };
});
