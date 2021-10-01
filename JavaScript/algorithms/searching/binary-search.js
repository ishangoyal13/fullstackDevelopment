// Searches for specific element in a given array using the binary search algorithm
// Time complexity: O(log N)

const binarySearch = (array, value, key) => {
	const id = (val) => val;
	const get = (key) => (val) => val[key];

	key = !key ? id : typeof key === 'string' ? get(key) : key;
	value = key(value);
	let middle = Math.floor(array.length / 2);
	let left = 0;
	let right = array.length;
	while (right >= left) {
		const middleValue = key(array[middle]);
		if (middleValue === value) {
			return middle;
		} else if (middleValue > value) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
		middle = Math.floor((left + right) / 2);
	}
	return -1;
};

console.log(binarySearch([1, 2, 3, 4, 6, 8], 1)); // result: 0
console.log(binarySearch([1, 8], 1)); // result: 0
console.log(binarySearch([1, 8], 8)); // result: 1
console.log(binarySearch([], 4)); // result: -1
console.log(binarySearch([{ x: 1 }, { x: 2 }, { x: 3 }], { x: 2 }, 'x')); // result: 1
