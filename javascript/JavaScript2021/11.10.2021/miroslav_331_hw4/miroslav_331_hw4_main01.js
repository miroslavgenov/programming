// С помощта на обектен литерал създайте обект person със свойства  име,
// години, роден град, функция за извеждане на обекта,
// функция за проверка дали лицето е от Бургас.​
// Добавете свойство фамилия и функция, връщаща инициалите на лицето.

var person = {
  name: "Alex",
  age: 10,
  "home city": "Burgas",
  showObj: () => {
    console.log(person);
  },

  checkBurgas: () => {
    const cityNames = [
      ["b", "u", "r", "g", "a", "s"],
      ["б", "у", "р", "г", "а", "с"],
    ];
    let personCity = person["home city"].toLowerCase().split("");

    function check(innerArray) {
      /* tazi funkciq shte proveri dali bukvite suvpadan 1 kum 1
             Arguments:
             
                innerArray:Number()
                    tova e parameter za cityNames
                    toi e za da se izbere koi pod niz e izbran dali na 
                    angliski e 0 ili na bulgarski 1
                    ot masiva cityNames[]

            */

      // cikul za personCity
      personCity.forEach((el, index) => {
        if (el != cityNames[innerArray][index]) {
          return false;
        }
      });

      // vrushta true ako ne e vurnalo false
      return true;
    }

    //ako duljinata na personCity e < frushta false
    if (personCity.length < cityNames[0].length) {
      return false;
    }
    //proverka za english version of Burgas
    else if (personCity[0] == cityNames[0][0]) {
      return check(0);
    }
    // this is for bulgarian version of Бургас
    else if (personCity[0] == cityNames[1][0]) {
      return check(1);
    }
  },
};

person.lastName = "Ivanov";
person.showPInfo = function () {
  return `${this.name} ${this.lastName} , ${this.age} from ${this["home city"]}`;
};

console.log("person.checkBurgas()");
console.log(person.checkBurgas());

console.log("person.showPInfo()");
console.log(person.showPInfo());
