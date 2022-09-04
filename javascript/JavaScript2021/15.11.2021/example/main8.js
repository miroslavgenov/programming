var f = document.myform;
// var sel = f.fields;
var sel = f.fields;
console.log(sel);
console.log(sel.options);
console.log(sel.length);
console.log(sel.size);
console.log(sel.selectedIndex);
console.log(sel.options[0].selected);
console.log(sel.options[1].selected);
console.log(sel.options[sel.selectedIndex].selected);

var sel1 = f.fields1;
var ops = Array.from(sel1.options);

ops.forEach((e) => console.log(e.text, e.value));

// for print the selected multiple elements
// go in browser and select 2 then type this
// script

// ops.forEach(e=>{
//     if(e.selected){
//     console.log(e.text);
//     }
//     })
var onlySelecter = ops.filter((e) => e.selected == true);
