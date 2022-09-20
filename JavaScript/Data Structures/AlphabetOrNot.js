// JS Program to check whether it is an alphabet or not.

function isAlphabet(X) {
  if (checkAlphabet(X)) {
    return "Yes";
  } else {
    throw "Not Alphabet";
  }
}

function checkAlphabet(X) {
  let n = X.charCodeAt(0);
  let strStartsWithALetter = (n >= 65 && n < 91) || (n >= 97 && n < 123);
  if (strStartsWithALetter) {
    return true;
  } else {
    return false;
  }
}
