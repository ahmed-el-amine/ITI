/**
 * @param {string} value
 * @description this function return whether the string is palindrome
 * @returns {boolean}
 */
function isPalindrome(value) {
  if (!value) return false;
  value = value.toString();
  return value == value.split("").reverse().join("") ? true : false;
}

console.log(isPalindrome("121"));
console.log(isPalindrome("aa"));
console.log(isPalindrome("bcb"));
console.log(isPalindrome("525"));
console.log(isPalindrome("9a5w"));
console.log(isPalindrome("qqqqq"));
console.log(isPalindrome(""));
console.log(isPalindrome(null));
console.log(isPalindrome(undefined));
console.log(isPalindrome(NaN));
console.log(isPalindrome(121));
