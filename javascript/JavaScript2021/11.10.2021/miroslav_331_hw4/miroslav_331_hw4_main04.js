// Примерна задача на JavaSctipt  (подобна на разгледаната)
// Създайте клас   Phone с член-данни  марка (brand) и цена (price)  и метод show(), 
// извеждащ описанието на телефона. 
// Създайте клас Phones със  свойство масив от телефони и следните свойства-методи:
// show()  - показва пълния списък  телефони
// minPrice() – извежда минималната цена на телефон в списъка
// showSel(minP, maxP) – показва списък с телефони, чиито цени са в зададения диапазон
// showBrand(br) – показва само телефоните със зададената марка
// countBrand(br)- определя броя на телефоните  от зададената марка
// discount(p) – намалява цените на всички телефони със зададения процент
// averagePrice()- определя средната цена на телефона

class Phone {

    constructor(brand, price) {
        this.brand = brand;
        this.price = price;
    }

    show() {
        console.log(`Brand: ${this.brand}\nPrice: ${this.price}`);
    };
}

class Phones {
    constructor(phoneList) {
        this.phoneList = [];

        phoneList.forEach(element => {
            this.phoneList.push(element);
        });

        // console.log(this.phoneList);
        // console.log(this.phoneList.length);// working
    }

    show() {
        console.log(this.phoneList);
    }
    minPrice() {
        this.phoneList.sort((a, b) => a.price - b.price);
        console.log(`Minimal price is: ${this.phoneList[0].price}`);
    }
    showSel(minP, maxP) {
        this.phoneList.forEach(element => {
            if (element.price >= minP && element.price <= maxP) {
                console.log(element);
            }
        })


    }
    showBrand(br) {
        this.phoneList.forEach(el => {

            if (el.brand.slice(0, el.brand.indexOf(' ')).toLowerCase() == br.toLowerCase()) {
                console.log(el);
            }
        })

    }
    countBrand(br) {
        let count = 0;
        this.phoneList.forEach(el => {

            if (el.brand.slice(0, el.brand.indexOf(' ')).toLowerCase() == br.toLowerCase()) {
                count++;

            }

        })
        console.log(count)
    }


    discount(p) {
        this.phoneList.map((x) => x.price = x.price - (x.price * (p / 100)));
        console.log(this.phoneList);
    }

    averagePrice() {
        // console.log(this.phoneList.length);

        // var prices = this.phoneList.map((x) => x.price);


        // prices = Math.floor(prices.reduce((x, y) => x + y) / this.phoneList.length);
        // console.log('Average price: ', prices)

        var average = this.phoneList.reduce((x, y) => x + y.price, 0) / this.phoneList.length;
        console.log(Math.floor(average));

    }

}

// main
var apple1 = new Phone('Apple iPhone 13 Pro Max', 2800);
var apple2 = new Phone('Apple iPhone 13 Pro Max', 1400);
var apple3 = new Phone('Apple iPhone XR', 750);

var huawei1 = new Phone('Huawei P50 Pro', 3000);
var huawei2 = new Phone('Huawei Mate 40E 4G', 2700);
var huawei3 = new Phone('Huawei nova 8 SE', 2500);

var google1 = new Phone('Google Pixel 5a 5G', 1000);
var google2 = new Phone('Google Pixel 4a 5G', 1200);
var google3 = new Phone('Google Pixel', 500);

var nokia1 = new Phone('Nokia G300', 1900);
var nokia2 = new Phone('Nokia X', 350);
var nokia3 = new Phone('Nokia ZC', 600);


// Phone test
console.log('nokia1.show()');
nokia1.show();
console.log('apple1.show()');
apple1.show();
// Phone test



//Phones test

var listWithPhones = new Phones(
    [
        apple1, apple2, apple3,
        huawei1, huawei2, huawei3,
        google1, google2, google3,
        nokia1, nokia2, nokia3
    ]
);

console.log('listWithPhones.show();');
listWithPhones.show();
console.log();


console.log('listWithPhones.minPrice();');
listWithPhones.minPrice();
console.log();

console.log('listWithPhones.showSel();');
listWithPhones.showSel(0, 2000);
console.log();

console.log('listWithPhones.showBrand(Apple);');
listWithPhones.showBrand('Apple');
console.log();

console.log('listWithPhones.countBrand(Apple);');
listWithPhones.countBrand('Apple');
console.log();

console.log('listWithPhones.discount(10);');
listWithPhones.discount(10);
console.log();

console.log('listWithPhones.averagePrice();');
listWithPhones.averagePrice();
console.log();
// main



