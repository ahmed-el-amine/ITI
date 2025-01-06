/**
 * @param {string} sentence
 * @description this function accept a sentence and return the longest word in sentence
 * @returns {string}
 */
function largeWord(sentence) {
  if (!sentence) return "";
  return sentence.split(" ").sort((a, b) => b.length - a.length)[0];
}

console.log(largeWord("Web Development Tutorial"));
console.log(largeWord(""));
console.log(largeWord());
