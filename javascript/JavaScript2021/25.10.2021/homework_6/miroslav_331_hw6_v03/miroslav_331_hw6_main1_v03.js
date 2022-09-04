var btnEl = document.getElementsByTagName("button");
var buttonsList = Array.from(btnEl);
var authors = document.getElementsByClassName("author");

function change() {
  let books = ["Cooking Time", "Burger Recepies"];
  let index = 0;
  let firstBook = authors[0].nextElementSibling;
  function increase() {
    if (index == 0) {
      index++;
      firstBook.innerText = books[index];
    } else {
      index--;
      firstBook.innerText = books[index];
    }
    return index;
  }
  return increase;
}

var ChangeBookTitle = change();

var myEvents = [
  () => {
    //add author
    let p = document.createElement("p");
    p.innerText = "Елин Пелин";
    p.className = "author";
    document.body.appendChild(p);
  },
  () => {
    // add book
    let div = document.createElement("div");
    div.innerText = "Random Book";
    div.className = "book";
    document.body.appendChild(div);
  },

  ChangeBookTitle,
  () => {
    // change Authors
    let authorList = Array.from(authors);
    console.log(authorList);
    if (authorList.length > 1) {
      let fAut = authorList[0].innerText;
      authorList[0].innerText = authorList[1].innerText;
      authorList[1].innerText = fAut;
    } else {
      window.alert("Need to add an author");
    }
  },
];

buttonsList.forEach((btn, index) =>
  btn.addEventListener("click", myEvents[index])
);
