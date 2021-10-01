const arr = ["string", 1, 2, "value", "string", 3, 2];

function deDuplicate(arr) {
  const hashmap = new Map();
  let left = 0,
    right = arr.length - 1;
  while (left < right) {
    let key = JSON.stringify(arr[left]);
    if (hashmap[key]) {
      [arr[left], arr[right]] = [arr[right], arr[left]];
      right -= 1;
    } else {
      hashmap[key] = true;
      left += 1;
    }
  }
  arr.splice(right + 1);
  return arr;
}

deDuplicate(arr);
console.log(arr);
// Output: [ 'string', 1, 2, 'value', 3 ]
