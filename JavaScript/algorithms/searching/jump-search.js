// Searches for specific element in a given array using the jump search algorithm
// Time complexity: O(log N)

const jumpSearch = (sortedArray, seekIndex) => {
	const arrayLength = sortedArray.length;
	if (!arrayLength) {
		return -1;
	}

	// set jumpSize
	const jumpSize = Math.floor(Math.sqrt(arrayLength));

	let blockStart = 0;
	let blockEnd = jumpSize;

	while (seekIndex > sortedArray[Math.min(blockEnd, arrayLength) - 1]) {
		blockStart = blockEnd;
		blockEnd += jumpSize;

		//  if out of array bounds exit
		if (blockStart > arrayLength) {
			return -1;
		}
	}

	let currentIndex = blockStart;
	while (currentIndex < Math.min(blockEnd, arrayLength)) {
		if (sortedArray[currentIndex] === seekIndex) {
			return currentIndex;
		}

		currentIndex += 1;
	}

	return -1;
};

console.log(jumpSearch([], 2)); // result: -1
console.log(jumpSearch([1, 2, 3, 4, 5, 6], 10)); // result: -1
console.log(jumpSearch([1, 2, 3, 4, 5, 6], 1)); // result: 0
console.log(jumpSearch([1, 2, 3, 4, 6, 8], 6)); // result: 4
