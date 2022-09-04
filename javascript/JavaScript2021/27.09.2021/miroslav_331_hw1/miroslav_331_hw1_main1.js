// A)
var word = "аз уча javascript";

var firstChar = word.charAt(0);// colect the first char "a" 

word = word.replace(firstChar, word[0].toUpperCase());// replace the first char with uppercase letter
// console.log(word)
// A)


//B
var charJ = 'j';

var wordJs = word.substring(word.indexOf(charJ));// substring the word when find the first 'j' char
// console.log(wordJs)
//B


//C
var charS = "s";
var wordJsUnmodified = word.substring(word.indexOf(charJ));// this is the string 'javascript' unmodified
wordJs = wordJs.replace(charJ, charJ.toUpperCase());// replace 'j' with 'J'
wordJs = wordJs.replace(charS, charS.toUpperCase());// replace 's' with 'S'
console.log(wordJs);

word = word.replace(wordJsUnmodified, wordJs); // replace 'javascript' with 'JavaScript'
console.log(word);
//C


//D
var studyWord = "уча";
var loveWord = "обичам";
word = word.replace(studyWord, loveWord); // replace 'уча' with 'обича'
console.log(word);
//D