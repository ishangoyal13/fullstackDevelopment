// Find the occurence of a name in an Array

function findOccurrence(names) {
  var occurence = new Map();

  names.forEach((element) => {
    if (occurence.has(element) == false) {
      occurence.set(element, 1);
    } else {
      let occurencevalue = occurence.get(element);
      occurence.set(element, occurencevalue + 1);
    }
  });

  return occurence;
}

names = ["rahul", "joey", "rahul", "jack"];
console.log(findOccurrence(names));
