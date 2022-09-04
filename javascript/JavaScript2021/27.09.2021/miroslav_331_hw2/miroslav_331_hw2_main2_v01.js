// Създайте масив от оценки, извлечете от него нов масив,
// съдържащ само оценките между 3 и 4, и определете броя на тези оценки​

var marks = [];
marks.length = 50;
marks.fill(0);

marks = marks.map((el) => (el = parseInt(Math.random() * 5) + 2));
console.log(marks);

var mark3Sum = marks.filter((e) => e == 3);

var mark4Sum = marks.filter((e) => e == 4);

console.log(`3-ki:\n${mark3Sum}\n4-ki:\n${mark4Sum}`);

var overAll = mark3Sum.length + mark4Sum.length;

console.log(
  `3-ki = ${mark3Sum.length} 4-ki = ${mark4Sum.length} \nobshot 3-ki i 4-ki = ${overAll} `
);
