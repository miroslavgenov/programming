let promise1 = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("done");
  }, 2000);
});
promise1.then((value) => console.log(value));

let promise2 = new Promise((resolve, reject) => {
  setTimeout(() => reject(new Error("Greshka!")), 200);
});
promise2.catch((err) => console.log(err));
