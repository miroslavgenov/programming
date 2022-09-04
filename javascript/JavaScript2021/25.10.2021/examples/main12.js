// vuvejda jiva kolekciq
// will point to the updated collection
var liveColection = document.getElementsByTagName("p");
console.log("before-> ", liveColection);

//vrushta kolekciq
// will not point to the updadet colection
var returnColection = document.querySelectorAll("p");
console.log("before-> ", returnColection);

// visqsht element
var new_element = document.createElement("p");

var div = document.querySelector("div");

//will insert before the div element
document.body.insertBefore(new_element, div);

console.log("after->> ", liveColection);
console.log();

console.log("after->", returnColection);
console.log();
