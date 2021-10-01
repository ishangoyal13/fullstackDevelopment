function createPattern(inputString) {
  let output = [],
    prev = inputString[0],
    count = 1,
    length = inputString.length;
  for (let index = 1; index < length; index++) {
    if (inputString[index] === prev) {
      count++;
    } else {
      if (count > 1) {
        output.push(inputString[index - 1]);
        output.push(count);
        count = 1;
        prev = inputString[index];
      } else {
        output.push(inputString[index - 1]);
        output.push(1);
      }
    }
  }
  output.push(inputString[length - 1]);

  if (count > 1) {
    output.push(count);
  } else {
    output.push(1);
  }

  return output.join('');
}

console.log(createPattern('abcbba'));
// Output: a1b1c1b1a2
