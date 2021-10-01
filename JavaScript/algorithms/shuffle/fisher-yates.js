// The shuffling algorithm of
// Fisher-Yates
// Time complexity: O(N)

const shuffle = (array) => {
	const size = array.length;
	for (var i = 0; i < size; i += 1) {
		let rand = Math.floor(i + Math.random() * (size - i));
		[array[rand], array[i]] = [array[i], array[rand]];
	}
	return array;
};

console.log(shuffle([18, 58, 46, 32, 78, 98, 1]));
