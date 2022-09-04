// Преобразувайте задача 2  в стила EcmaScript 6  - с използване на класове


class Movie {

    constructor(name, year, country, rating) {
        this.name = name;
        this.year = year;
        this.country = country;
        this.rating = rating;
    }
    getMovieInfo() {
        return `${this.name}, ${this.year},${this.country}, ${this.rating}`
    }
    getTitleAndYear() { return `Title:${this.name} \nYear:${this.year}` }

    setRating(value) {
        this.rating = value != undefined ? this.rating = value : 0;
    }
};

var myMovie = new Movie('Glass', 2021, 'UK', 100);

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