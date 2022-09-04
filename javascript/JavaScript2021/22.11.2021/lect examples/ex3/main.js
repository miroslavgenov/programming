let prom1 = new Promise((res, rej) => {
  res("xx");
});
prom1.then((msg) => console.log(msg));

let prom2 = new Promise((res, rej) => {
  // res("hello");
  rej(new Error("Hello world how are you"));
});
// prom2.then((msg) => console.log(msg));
prom2.catch((msg) => console.log(msg));
