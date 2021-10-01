// Truncate function to limit text by length
// str is a parameter that acts as a variable you want to limit
// n is the limit of length that you want

const truncate = (str, n) => {
  return str.length > n ? str.substring(0, n - 1) + "..." : str;
};