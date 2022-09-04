//Tazi zadacha sudurja 3 usloviq 4-to , 5-to i 6-to uslovie

// Създайте списък с имена и  извлечете от
//  него само имената, завършващи на “a”
var namesList = [
  "Darla",
  "Yuk",
  "Thurmanaaa",
  "Lessie",
  "Kristian",
  "Lucienne",
  "Dennis",
  "Sumiko",
  "Alfonso",
  "Savanna",
  "Ceola",
  "Ginette",
  "Maggie",
  "Angila",
  "Hope",
  "Laticia",
  "Sunny",
  "Gina",
  "Jannet",
  "Retta",
];

console.log(
  'Имена завършващи на "а"',
  namesList.filter((x) => x.charAt(x.length - 1) == "a")
);

// Oт списъка с имената  върнете нов списък,
//  в който имената са съкратени до първите три  букви​

var newNamesList = namesList.map((el) => el.slice(0, 3));
console.log("Onlie 3 letters\n", newNamesList);

//Определете максималния брой гласни букви,
//които се съдържат в име от списък с имена
//(първо получете масив с броя на гласните във всяко име)​

var allNamesLower = namesList.map((e) => e.toLowerCase());

//glasni
// var vowelsChars = ["a", "e", "i", "o", "u"];
// vrushta masiv ot glasni za vsqko ime //shte vurne shte stane vlojen masiv
var vowesFilter = allNamesLower.map((name) => {
  return name.split("").filter((charName) => {
    return (
      charName == "a" ||
      charName == "e" ||
      charName == "i" ||
      charName == "o" ||
      charName == "u"
    );
  });
});

namesList.forEach((name, index) => {
  console.log(name, "ima glasni", vowesFilter[index].length);
});

var vowlen = vowesFilter.map((e) => e.length);
console.log(vowlen);
var moreIndx = [0];

//
var [vowelNamesMaxLength, lenghtMax] = vowlen.reduce(
  function ([listIndexes, greater], element, index) {
    if (element > greater) {
      listIndexes = [];
      greater = element;
      listIndexes.push(index);
    } else if (element == greater) {
      listIndexes.push(index);
    }
    return [listIndexes, greater];
  },
  [[], 0]
);

if (vowelNamesMaxLength.length > 1) {
  console.log(`${vowelNamesMaxLength.length} човека с максимален брой гласни:`);
  vowelNamesMaxLength.forEach((e) => {
    console.log(namesList[e], vowesFilter[e].length, "гласни букви");
  });
} else {
  console.log(
    "1 човек с максимален брой гласни:\n",
    namesList[vowelNamesMaxLength[0]],
    vowesFilter[vowelNamesMaxLength[0]].length
  );
}
