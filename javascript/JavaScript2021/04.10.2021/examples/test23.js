var add = function (a, b) {
    return a() + b();
};

function one() { return 1; }
function two() { return 2; }

// anonimno dobavqne na na funkciq
console.log(add(() => 1, () => 3));

console.log(add(one, two));

console.log(
    add(
        function () { return 1; },
        function () { return 9; }
    )
);