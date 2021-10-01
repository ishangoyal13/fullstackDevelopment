// Finds the maximum sum of the elements of a subarray in a given array
// using the Kadane's algorithm
// For example, for the sequence of values -2, 1, -3, 4, -1, 2, 1, -5, 4
// the contiguous subarray with the largest sum is 4, -1, 2, 1, with sum 6

const maxSubarray = (array) => {
	let currentMax = array[0];
	let max = array[0];
	for (let i = 1; i < array.length; i += 1) {
		currentMax = Math.max(array[i], currentMax + array[i]);
		max = Math.max(max, currentMax);
	}
	return max;
};

console.log(maxSubarray([-2, 1, -3, 4, -1, 2, 1, -5, 4])); // 6
