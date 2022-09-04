// tova sa strings elementite koito shte se dobavqt
// const INPUTBUTTONELEMENTSTRING = ["input", "button"];

var elementsClassAuthor = document.getElementsByClassName("author");
let listElementsClassAuthor = Array.from(elementsClassAuthor);

//input elements
const INPUTIDNAMES = ["addAndComp", "addBook", "CompandComp"];
const INPUTHINT = ["Автор", "Книга", "Автор , Автор"];
var inputElements = [];
inputElements.length = INPUTIDNAMES.length;
inputElements.fill(0);

inputElements = inputElements.map((e, i) => {
  e = document.createElement("input");
  e.id = INPUTIDNAMES[i];
  e.placeholder = INPUTHINT[i];
  e.placeHolder = document.body.insertBefore(e, elementsClassAuthor[0]);
  return e;
});

//button elements
// buttons innerText
const BUTTONINNERTEXT = [
  "Добави Автор",
  "Добави книги на автор",
  "Заменете първата на книга с нова",
  "Разменете местата на двата автора",
];

var buttonElements = [];
buttonElements.length = BUTTONINNERTEXT.length;
buttonElements.fill(0);

var listEventFunctionsForButton = [
  //   function addAuthor(button) {
  //     function x() {
  //       button.style.colo = "red";
  //     }
  //     return x;
  //   },
  function addBookToAuthor() {},
  function replaceFirstAuthorBook() {},
  function replaceAuthors() {},
];

var listFunct = [
  function addAuthor(btn) {
    function x() {
      // console.log(inputElements[0].value.length);
      if (inputElements[0].value.length != 0) {
        let p = document.createElement("p");
        p.innerText = inputElements[0].value;
        p.className = "author";
        document.body.append(p);
        // console.log(elementsClassAuthor);
      }
    }
    return x;
  },
  function addBookToAuthor(_) {
    function x() {
      let listElementsClassAuthor = Array.from(elementsClassAuthor);
      // if input and the autors is equal will add book
      listElementsClassAuthor.forEach((el) => {
        if (el.innerText == inputElements[0].value) {
          let new_book = document.createElement("div");

          new_book.className = "book";
          new_book.innerText = inputElements[1].value;
          document.body.insertBefore(new_book, el.nextElementSibling);
        }
      });
    }
    return x;
  },
  function replaceFirstAuthorBook(_) {
    function x() {
      // tyk pravq sushtoto kakto v addBookToAuthor
      let listElementsClassAuthor = Array.from(elementsClassAuthor);
      listElementsClassAuthor.forEach((au) => {
        if (au.innerText == inputElements[0].value) {
          let new_book = document.createElement("div");

          new_book.className = "book";
          new_book.innerText = inputElements[1].value;
          // vzimam na avtora sledvashtiq element eu.nextElementSubling
          document.body.replaceChild(new_book, au.nextElementSibling);
        }
      });
    }
    return x;
  },
  function replaceAuthors(_) {
    function x() {
      let regEx = /(.*) *, *(.*)/gi;
      let authorsForCompList = [];
      let listElementsClassAuthor = Array.from(elementsClassAuthor);
      if (regEx.exec(inputElements[2].value)) {
        authorsForCompList.push(RegExp.$1);
        authorsForCompList.push(RegExp.$2);
        console.log(authorsForCompList[0], authorsForCompList[1]);

        // listElementsClassAuthor[0].innerText = "hii";
      }
    }

    return x;
  },
];

buttonElements = buttonElements.map((e, i) => {
  e = document.createElement("button");
  e.innerText = BUTTONINNERTEXT[i];
  e.addEventListener("click", listFunct[i](e));
  document.body.insertBefore(e, listElementsClassAuthor[0]);
  return e;
});

// buttonElements.forEach((e) => {});

// buttonElements.forEach(e=>{

// })

// сухранява всички инпут и бутони
//  author,book

// // HTML COLLECTION LIVE
// var authors = document.getElementsByClassName("author");
// // ARRAy with authors
// var authorsList = Array.from(authors);

// var functions = [
//   function addAuthor(_) {
//     function x() {
//       // if the author input !="" will create new author
//       if (listElements[0].value != "") {
//         let p = document.createElement("p");
//         p.className = "author";
//         p.innerText = listElements[0].value;
//         document.body.appendChild(p);
//         listElements[0].value = "";
//       }
//     }
//     return x;
//   },

//   function addBookToAuthor(_) {
//     function x() {
//       // if input and the autors is equal will add book
//       authorsList.forEach((el) => {
//         if (el.innerText == listElements[0].value) {
//           let new_book = document.createElement("div");

//           new_book.className = "book";
//           new_book.innerText = listElements[2].value;
//           document.body.insertBefore(new_book, el.nextElementSibling);
//         }
//       });
//     }
//     return x;
//   },
//   function replaceFirstAuthorBook(_) {
//     function x() {
//       // tyk pravq sushtoto kakto v addBookToAuthor

//       authorsList.forEach((au) => {
//         if (au.innerText == listElements[0].value) {
//           let new_book = document.createElement("div");

//           new_book.className = "book";
//           new_book.innerText = listElements[2].value;
//           // vzimam na avtora sledvashtiq element eu.nextElementSubling
//           document.body.replaceChild(new_book, au.nextElementSibling);
//         }
//       });
//     }
//     return x;
//   },
//   function replaceAuthors(_) {
//     function x() {
//       let regEx = /(.*) *, *(.*)/;

//       // proverka za edintichnost
//       let check = [false, false];
//       // obekt suhranqvash poziciqta na avtorite
//       let authorpos = { auPos1: 0, auPos: 0 };

//       let authors = document.getElementsByClassName("author");
//       let authorsList = Array.from(authors);

//       // tyk shte tursq kude ima suvpadenie m/y avtorite
//       // i ako ima zapisvam true i poziciqta
//       // no ako ima poveche avtori s ednakvi imena shte
//       // razmeni poslednoto no ne sum go testval
//       if (regEx.test(listElements[1].value)) {
//         var au1 = listElements[1].value.slice(
//           0,
//           listElements[1].value.indexOf(",")
//         );
//         var au2 = listElements[1].value.slice(
//           listElements[1].value.indexOf(",") + 1
//         );
//         au1 = au1.replaceAll(" ", "");
//         au2 = au2.replaceAll(" ", "");
//       }

//       authorsList.forEach((au, index) => {
//         if (au.innerText.replaceAll(" ", "") == au1) {
//           authorpos.auPos1 = index;
//           check[0] = true;
//         }
//         if (au.innerText.replaceAll(" ", "") == au2) {
//           check[1] = true;
//           authorpos.auPos = index;
//         }
//       });

//       // // tova oznachava che avtor 1 i avtor 2 gi ima
//       // //i se pravi razmqnata
//       if (check[0] && check[1]) {
//         let temp = "";
//         temp = authorsList[authorpos.auPos1].innerText;
//         authorsList[authorpos.auPos1].innerText =
//           authorsList[authorpos.auPos].innerText;
//         authorsList[authorpos.auPos].innerText = temp;
//       }
//     }

//     return x;
//   },
// ];

// // creates eventListeners to all buttons
// listElements.slice(3).forEach((el, index) => {
//   el.addEventListener("click", functions[index](el));
// });
