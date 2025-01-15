export function calculateGuessCount(wordLength, level) {
  if (level === "easy") {
    return Math.min(9, Math.max(5, wordLength));
  } else if (level === "medium") {
    return Math.min(6, Math.max(4, wordLength));
  } else if (level === "hard") {
    return Math.min(4, Math.max(2, wordLength));
  }
}

export function randomNumber(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}
