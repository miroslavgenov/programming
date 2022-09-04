function message1(a, b) {
    console.log(` ${a} ${b}`);


}

function message2(list) {
    console.log(list)
}

// call predava otdelni elementi
message1.call('hello', 'world');

message2.apply(['hello', 'world']);
