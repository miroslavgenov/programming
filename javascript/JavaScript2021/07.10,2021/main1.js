
let ar = []; // празен масив
let b = [1, 4, 5, 'hi'];  // масив с 4 елемента, индекси 0, 1, 2, 3
let c = b[1]; // 4
let d = ['a', 'b', , '!']; // индекси 0, 1, 3
document.write('<h3>for (i = 0; i < le3ngth; i++)</h3>');

for (let i = 0; i < d.length; i++)
    document.write(`<p>${i} --> ${d[i]}</p>`);

d[5] = '.'; // присвоява стойност на елемент с индекс 5
const v01 = 3.14;
d.push(v01); // присвоява стойност на елемента с индекс с 1 по-голям от последния
let v02 = 'array';
d.unshift(v02); // измества надясно елементите на масива и присвоява стойност на елемента с освободилия се индекс
document.write('<h3>for (j in d)</h3>');

for (let j in d)
    document.write(`<p>${j} --> ${d[j]}</p>`);
document.write('<h3>след shift и pop</h3>');
let f = d.shift();
let l = d.pop();
document.write(`<h3>получен с shift: ${f}, получен с pop: ${l}</h3>`);

for (let k in d)
    document.write(`<p>${k} --> ${d[k]}</p>`);
d.splice(1, 2, 'new element 1', 'new element 2', 'new element 3'); // премахва 2 елемента започвайки от този с индекс 1 и на тяхно място добавя посоченото като параметри 3, 4 и 5
document.write("<h3>след splice(1, 2, 'new element 1', 'new element 2', 'new element 3')</h3>");

for (let m in d)
    document.write(`<p>${m} --> ${d[m]}</p>`);
