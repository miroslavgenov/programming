var table = [
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0],
];

// тестови променливи
// var indei = 1,  indej = 0;
// var queen = 2;
// var correctResult = [];
//

// тези променливи ги използвам в test , но
// се е много коректно
var isTrue = false;
var isFalse = true;
var currentPos = false;
//

// main
(function main() {
  place(1, 0);
})();
// main

function init() {
  // функция поставя първата царица
  table = [
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
  ];
  test(0, 0);
} //function ini

function place(posI, posJ) {
  // функция която мисля да е за backtrack , но
  // съм забравил как да да се направи
  currentPos = false;
  test(posI, posJ);

  if (currentPos == true) {
    show(table);
    console.log();

    if (posJ + 1 < table.length) {
      place(posI, posJ + 1);
      // // init();
      posJ = 0;
      place(posI + 1, posJ + 1);
    } //if (posJ + 1 < table.length)
  } //if (currentPos == true)
} //function place(posI, posJ)

function show(arr) {
  // принтира цялата табла
  arr.forEach((element) => {
    console.log(`${element}`);
  });
} //show

function checkForLoop(indexI, indexJ) {
  // тази функция ще проверява дали
  // през даданият ред сме минали вече за да
  // предотврати безкрайното му повтаряне

  // тук се брой , сигурно има и други начини
  // изчислявам броя има 8 хода на едни ред
  // с 2 се отбелязва дали сме минали и става 8*2 = 24
  // ако е вярно връща true
  //ако не е false няма цикъл
  var count = table[indexI].reduce((a, e) => a + e);
  if (count == 16) {
    return true;
  } //if
  else {
    false;
  } //else
} //checkForLoop

function myClean() {
  // функция, която почисва
  // след като сме поставили царица
  // използвам for each за вътрепният елемент
  // после map за да запазя промяната
  table.forEach((e, i, arr) => {
    arr[i] = e.map((elem) => {
      if (elem == 2) {
        return (elem = 0);
      } //if
      else {
        return elem == 1 ? 1 : 0;
      } //else
    }); //arr[i].map
  }); //table.forEach
} // myClean

function test(indexI, indexJ) {
  if (indexI == 7 && indexJ == 7 && checkForLoop(indexI, indexJ) == true) {
    myClean();
    isFalse = false;
    return isFalse;
  } //if
  // тази функция поставя царицата използвам рекурсия
  // и функциите които направих за хоризонтал вертикал
  // диагонал долен ляв горен десен
  // долен десен горен горен ляв

  // проверка дали сме в лооп
  // ако сме в лооп увеличаваме вертикала
  if (checkForLoop(indexI, indexJ) == true) {
    if (indexI + 1 < table.length) {
      test(indexI + 1, 0);
      return;
    } //if
  } //if

  // тук присвоявам променливите дали царица преминава
  // през друга царица
  let dR = diagonalRight(indexI, indexJ);
  let dL = diagonalLeft(indexI, indexJ);
  let v = vertical(indexI, indexJ);
  let h = horizontal(indexI, indexJ);

  if (h == 0) {
    table[indexI][indexJ] = table[indexI][indexJ] == 1 ? 1 : 2;
    if (indexI + 1 < table.length) {
      test(indexI + 1, indexJ);
      return;
    } // if (indexI + 1 < table.length)
    else {
      if (indexI == 7) {
        myClean();
        isFalse = false;
        return isFalse;
      }
      test(0, indexJ);
      return;
    } //else
  } //if (h==0)
  else if (h == 1) {
    if (v == 0) {
      table[indexI][indexJ] = table[indexI][indexJ] == 1 ? 1 : 2;

      if (indexJ + 1 < table.length) {
        test(indexI, indexJ + 1);
        return;
      } //if (indexJ + 1 < table.length)
      else {
        test(indexI, 0);
        return;
      } //else
    } //if (v == 0)
    else if (v == 1) {
      if (dR == 0) {
        table[indexI][indexJ] = table[indexI][indexJ] == 1 ? 1 : 2;
        if (indexJ + 1 < table.length) {
          test(indexI, indexJ + 1);
          return;
        } // if (indexJ + 1 < table.length)
        else {
          test(indexI, 0);
          return;
        } //else
      } // if (dR == 0)
      else if (dR == 1) {
        if (dL == 0) {
          table[indexI][indexJ] = table[indexI][indexJ] == 1 ? 1 : 2;
          if (indexJ + 1 < table.length) {
            test(indexI, indexJ + 1);
            return;
          } // if (indexJ + 1 < table.length)
          else {
            test(indexI, 0);
            return;
          } // else
        } //if (dL == 0)
        else if (dL == 1) {
          table[indexI][indexJ] = 1;
          //indei = indexI;
          //indej = indexJ;
          currentPos = true;
          myClean();

          if (table[indexI][indexJ] == 1) {
          } //if (table[indexI][indexJ] == 1)

          if (indexI == 7) {
            isTrue = true;
            return isTrue;
          } //if (indexI == 7)
        } // else if (dL == 1)
      } //else if (dR == 1)
    } // else if (v == 1)
  } // else if (h == 1)
} //test

function diagonalLeft(indexI, indexJ) {
  // проверка на долен ляв и горен десен диагонал
  if (table[indexI][indexJ] == 1) {
    return false;
  } //if
  else {
    // долен ляв
    for (let i = indexI, j = indexJ; i < table.length && j >= 0; i++, j--) {
      if ((j - 1 >= 0) & (i + 1 < table.length)) {
        if (table[i + 1][j - 1] == 1) {
          return false;
        } //if
      } //if
    } //for
    //горен десен
    for (let i = indexI, j = indexJ; i >= 0 && i < table.length; i--, j++) {
      if (i - 1 >= 0 && j + 1 < table.length) {
        if (table[i - 1][j + 1] == 1) {
          return false;
        } //if
      } //if
    } //for
  } //else
  return true;
} //function diagonalLeft

// show(table);

function diagonalRight(indexI, indexJ) {
  // проверка към долния десен диагонал към горен ляв
  if (table[indexI][indexJ] == 1) {
    return false;
  } // if
  else {
    // долен десен
    for (let i = indexI; i < table.length; i++) {
      if (i + 1 < table.length) {
        if (table[i + 1][indexJ + i] == 1) {
          return false;
        } //if
      } //if
    } //for
    // горен ляв
    for (let i = indexI, j = indexJ; i >= 0 && j >= 0; i--, j--) {
      if (i - 1 >= 0 && j - 1 >= 0) {
        if (table[i - 1][j - 1] == 1) {
          return false;
        } //fi
      } //if
    } //for
  } //else
  return true;
} //function diagonalRight

// show(table);

function vertical(indexI, indexJ) {
  // проверка по вертикал
  if (
    table[0][indexJ] == 1 ||
    table[table.length - 1][indexJ] == 1 ||
    table[indexI][indexJ] == 1
  ) {
    return false;
  } //if
  else {
    for (let i = 0; i < table.length; i++) {
      if (table[i][indexJ] == 1) {
        return false;
      } //if
    } //for
    return true;
  } //else
} //function vertical

function horizontal(indexI, indexJ) {
  // проверка по хоризонт
  if (
    table[indexI][0] == 1 ||
    table[indexI][table.length - 1] == 1 ||
    table[indexI][indexJ] == 1
  ) {
    return false;
  } //if
  else {
    for (let j = 0; j < table.length; j++) {
      if (table[indexI][j] == 1) {
        return false;
      } //if
    } //for
    return true;
  } // else
} //function horizontal(indexI, indexJ)
