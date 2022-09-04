// 2.  Напишете  конструктор  Movie  (филм)  със свойства name (име на филма),
// year(година на създаване),  country (държава) rating (рейтинг на филма).
//  В прототипа на конструктора включете метод за извеждане на информацията за филма, 
// метод за промяна на рейтинга,
//   методи за извличане на рейтинга и заглавието.   ​

//  В конструктора на Movie   добавете свойство artists- масив от участващи 
// във филма артисти(първоначално може да е празен),
//  а в прототипа  на конструктора- методи за добавяне на артисти в масива,
//   за извеждане на масива  от артисти, и за проверка дали даден артист участва във филма. ​

function Movie(name, year, country, rating) {
    this.name = name;
    this.year = year;
    this.country = country;
    this.rating = rating;
};

Movie.prototype = {
    getMovieInfo: function () {
        return `${this.name}, ${this.year},${this.country}, ${this.rating}`
    },
    getTitleAndYear: function () { return `Title:${this.name} \nYear:${this.year}` }
}

Movie.prototype.setRating = function (value) {
    this.rating = value != undefined ? this.rating = value : 0;
}



var myMovie = new Movie('Hello world', 1970, 'BG', '50');

console.log('myMovie.getMovieInfo()');
console.log(myMovie.getMovieInfo());
console.log();

console.log('myMovie.setRating(555)');
myMovie.setRating(555);
console.log(myMovie.getMovieInfo());
console.log();

console.log('myMovie.getTitleAndYear()');
console.log(myMovie.getTitleAndYear());
console.log();

