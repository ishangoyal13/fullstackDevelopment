
// remove duplicate values from array 
const names = ['Sam', 'Joe', 'Paul', 'Ringo', 'Sam'];

let unique = [...new Set(names)];
console.log(unique);
