// Program to demonstrate how to use Promises in JavaScript which is introduced in 2015 as an ES6 update.
// The Promise object represents the eventual completion (or failure) of an asynchronous operation and its resulting value.

const prop1 = false;
const prop2 = true;

function callback() {
  return new Promise((resolve, reject) => {
    if (prop1) {
      reject({
        name: "prop1",
        message: "this is error message of prop1",
      });
    } else if (prop2) {
      reject({
        name: "prop2",
        message: "this is error message of prop2",
      });
    } else {
      resolve("Everything is working");
    }
  });
}

callback()
  .then((res) => {
    console.log(res);
  })
  .catch((err) => {
    console.log(`${err.name} ${err.message}`);
  });

let user = {
  name: "John Doe",
  email: "johndoe@gmail.com",
  password: "12345",
  number: "0123456789"
}

console.log(user);
