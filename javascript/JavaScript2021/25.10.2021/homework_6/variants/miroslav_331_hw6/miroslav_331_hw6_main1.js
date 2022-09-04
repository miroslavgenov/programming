// tova sa strings elementite koito shte se dobavqt
var inputAndButton = ["input", "button"];

// button inputText
var buttonNameList = [
  "Добави Автор",
  "Добави книги на автор",
  "Заменете първата книга с нова",
  "Разменете местата на двата автора",
];
// vzima vsichki elementi s class author
var author = document.body.firstElementChild;
// сухранява всички инпут и бутони
//  author,book
// [input,input , button,button,button,button]
var listElements = [];

// if index is 0 adds 2 inputs one for Автор second Книга
// if index i !=0 adds 4 buttons
inputAndButton.forEach((e, index) => {
  if (index == 0) {
    listElements.push(document.createElement(e));
    listElements.push(document.createElement(e));
    listElements[index].placeholder = "Автор";
    listElements[index + 1].placeholder = "Книга";
    document.body.insertBefore(listElements[index], author);
    document.body.insertBefore(listElements[index + 1], author);
  } else {
    // adds button text
    buttonNameList.forEach((el, j) => {
      listElements.push(document.createElement(e));
      listElements[j + 2].innerText = el;
      document.body.insertBefore(listElements[j + 2], author);
    });
  }
});

var functions = [
  function addAuthor(element) {
    function x() {
      // if the author input !="" will create new author
      if (listElements[0].value != "") {
        let p = document.createElement("p");
        p.className = "author";
        p.innerText = listElements[0].value;
        document.body.appendChild(p);
        listElements[0].value = "";
      }
    }
    return x;
  },

  function addBookToAuthor(element) {
    function x() {
      // HTML COLLECTION LIVE
      let authors = document.getElementsByClassName("author");
      // ARRAy with authors
      let authorsList = Array.from(authors);

      // if input and the autors is equal will add book
      authorsList.forEach((el) => {
        if (el.innerText == listElements[0].value) {
          let new_book = document.createElement("div");

          new_book.className = "book";
          new_book.innerText = listElements[1].value;
          document.body.insertBefore(new_book, el.nextElementSibling);
        }
      });
    }
    return x;
  },
  function replaceFirstAuthorBook(element) {
    function x() {
      // tyk pravq sushtoto kakto v addBookToAuthor
      let authors = document.getElementsByClassName("author");
      let authorList = Array.from(authors);

      authorList.forEach((au) => {
        if (au.innerText == listElements[0].value) {
          let new_book = document.createElement("div");

          new_book.className = "book";
          new_book.innerText = listElements[1].value;
          // vzimam na avtora sledvashtiq element eu.nextElementSubling
          document.body.replaceChild(new_book, au.nextElementSibling);
        } else {
          alert(`Липсва този автор: ${listElements[0].value}`);
        }
      });
    }
    return x;
  },
  function replaceAuthors(element) {
    function x() {
      // proverka za edintichnost
      let check = [false, false];
      // obekt suhranqvash poziciqta na avtorite
      let authorpos = { auPos1: 0, auPos: 0 };

      let authors = document.getElementsByClassName("author");
      let authorList = Array.from(authors);

      // tyk shte tursq kude ima suvpadenie m/y avtorite
      // i ako ima zapisvam true i poziciqta
      // no ako ima poveche avtori s ednakvi imena shte
      // razmeni poslednoto no ne sum go testval
      authorList.forEach((au, index) => {
        if (au.innerText == listElements[0].value) {
          authorpos.auPos1 = index;
          check[0] = true;
        }
        if (au.innerText == listElements[1].value) {
          check[1] = true;
          authorpos.auPos = index;
        }
      });
      // tova oznachava che avtor 1 i avtor 2 gi ima
      //i se pravi razmqnata
      if (check[0] && check[1]) {
        let temp = "";
        temp = authorList[authorpos.auPos1].innerText;
        authorList[authorpos.auPos1].innerText =
          authorList[authorpos.auPos].innerText;
        authorList[authorpos.auPos].innerText = temp;
      }
    }
    return x;
  },
];

// creates eventListeners to all buttons
listElements.slice(2).forEach((el, index) => {
  el.addEventListener("click", functions[index](el));
});
