import { GameLevels, GameState, WinLoseState } from "./constants.js";
import { WordsDB, arabicLetters } from "./data.js";
import Timer from "./timer.js";
import { randomNumber } from "./utils.js";

const HangmanGame = {
  level: GameLevels.easy,
  levelElement: null,
  topicsElement: null,
  startGameBTNElement: null,
  restartGameBTNElement: null,
  gameSettingsElement: null,
  gameBoardElement: null,
  hintValueElement: null,
  hintLevelValueElement: null,
  hintCountValueElement: null,
  inputKeysElement: null,
  inputResultElement: null,
  noteTextElement: null,
  timerElement: null,
  gameTimer: null,
  hint: null,
  word: null,
  maxGuessCount: 0,
  guessCount: 0,
  wrongGuess: [],
  correctGuess: [],
  gameState: GameState.ready,

  initialGame: function () {
    // reset all game values
    HangmanGame.level = GameLevels.easy;
    HangmanGame.levelElement = document.querySelector("#level");
    HangmanGame.topicsElement = document.querySelector("#topics");
    HangmanGame.gameSettingsElement = document.querySelector(".game-settings");
    HangmanGame.startGameBTNElement = document.querySelector("#startTheGameBTN");
    HangmanGame.restartGameBTNElement = document.querySelector("#restartTheGameBTN");
    HangmanGame.gameBoardElement = document.querySelector("#game-board");
    HangmanGame.hintValueElement = document.querySelector(".hint-value");
    HangmanGame.hintLevelValueElement = document.querySelector(".hint-level-value");
    HangmanGame.hintCountValueElement = document.querySelector(".hint-count-value");
    HangmanGame.inputKeysElement = document.querySelector(".container-input-keys");
    HangmanGame.inputResultElement = document.querySelector(".container-input-result");
    HangmanGame.noteTextElement = document.querySelector(".note-text");
    HangmanGame.timerElement = document.getElementById("timer-count");
    HangmanGame.hint = null;
    HangmanGame.word = null;
    HangmanGame.guessCount = null;
    HangmanGame.wrongGuess = [];
    HangmanGame.correctGuess = [];
    HangmanGame.gameState = GameState.ready;

    HangmanGame.noteTextElement.innerText = "";
    HangmanGame.noteTextElement.classList.remove("win-text");
    HangmanGame.noteTextElement.classList.remove("lose-text");
    // add some events
    HangmanGame.startGameBTNElement.addEventListener("click", HangmanGame.startTheGame);
    HangmanGame.restartGameBTNElement.addEventListener("click", HangmanGame.resetGame);
  },

  createKeyElement: function (letter) {
    const element = document.createElement("div");
    element.innerText = letter;
    element.classList.add("input-key");
    element.addEventListener("click", function (element) {
      HangmanGame.guessTheLetter(element.target, letter);
    });
    return element;
  },

  createInputElement: function () {
    const element = document.createElement("div");
    element.classList.add("input-value");
    return element;
  },

  displayInputsKeys: function () {
    // remove prev elements
    HangmanGame.inputKeysElement.innerHTML = "";
    // add new elements
    arabicLetters.map(function (e) {
      HangmanGame.inputKeysElement.appendChild(HangmanGame.createKeyElement(e));
    });
  },

  guessTheLetter: function (element, letter) {
    if (HangmanGame.gameState != GameState.started) return;
    if (HangmanGame.guessCount <= 0 || HangmanGame.wrongGuess.includes(letter)) return;

    const indexes = [];
    for (const idx in HangmanGame.word.split("")) {
      if (HangmanGame.word[idx] == letter) indexes.push(idx);
    }

    if (indexes.length <= 0) {
      element.classList.add("input-key-wrong");
      HangmanGame.wrongGuess.push(letter);
      HangmanGame.guessCount--;
    } else {
      for (const idx of indexes) {
        HangmanGame.inputResultElement.childNodes[idx].innerText = letter;
        HangmanGame.correctGuess[idx] = letter;
      }
      element.classList.add("input-key-selected");
    }
    HangmanGame.hintCountValueElement.innerText = HangmanGame.guessCount;
    HangmanGame.checkWin();
  },

  checkWin: function () {
    if (HangmanGame.word === HangmanGame.correctGuess.join("")) {
      return HangmanGame.endGame(WinLoseState.win);
    }
    if (HangmanGame.guessCount <= 0) {
      HangmanGame.endGame(WinLoseState.lose);
    }
  },

  selectWord: function () {
    let obj;
    switch (HangmanGame.level) {
      case GameLevels.hard:
        obj = Object.entries(WordsDB.hard);
        break;
      case GameLevels.medium:
        obj = Object.entries(WordsDB.medium);
        break;
      default:
        obj = Object.entries(WordsDB.easy);
        break;
    }
    // select random topic
    const [key, value] = obj.find((x) => x[0] == HangmanGame.topicsElement.value) || obj[randomNumber(0, obj.length - 1)];
    // select random keyword of this topic
    HangmanGame.word = value[randomNumber(0, value.length - 1)].value;
    HangmanGame.guessCount = value[randomNumber(0, value.length - 1)].guessCount;
    HangmanGame.maxGuessCount = HangmanGame.guessCount;
    HangmanGame.hint = key;
    HangmanGame.hintCountValueElement.innerText = HangmanGame.maxGuessCount;
    HangmanGame.hintLevelValueElement.innerText = HangmanGame.level;
    HangmanGame.hintValueElement.innerText = HangmanGame.hint;
  },

  displayInputsFields: function () {
    // remove old elements
    HangmanGame.inputResultElement.innerHTML = "";
    // add new elements
    HangmanGame.word.split("").map((x) => {
      HangmanGame.inputResultElement.appendChild(HangmanGame.createInputElement());
    });
  },

  startTheGame: function () {
    switch (HangmanGame.levelElement.value) {
      case GameLevels.medium:
        HangmanGame.level = GameLevels.medium;
        break;
      case GameLevels.hard:
        HangmanGame.level = GameLevels.hard;
        break;
      default:
        HangmanGame.level = GameLevels.easy;
        break;
    }

    // display all Inputs Keys
    HangmanGame.displayInputsKeys();
    // select word and display the hint
    HangmanGame.selectWord();
    // display input fields
    HangmanGame.displayInputsFields();

    HangmanGame.gameState = GameState.started;

    HangmanGame.gameTimer = new Timer(HangmanGame.timerElement, 60, () => {
      HangmanGame.endGame(WinLoseState.lose);
    });

    HangmanGame.gameTimer.start();

    HangmanGame.gameSettingsElement.classList.add("hide");
    HangmanGame.gameBoardElement.classList.remove("hide");
  },

  endGame: function (status) {
    HangmanGame.gameTimer.stop();
    HangmanGame.gameState = GameState.finished;
    if (status == WinLoseState.win) {
      HangmanGame.showMessage(status);
      return;
    }
    HangmanGame.showMessage(status);
  },

  resetGame: function () {
    HangmanGame.gameTimer.stop();
    HangmanGame.initialGame();
    HangmanGame.gameSettingsElement.classList.remove("hide");
    HangmanGame.gameBoardElement.classList.add("hide");
  },

  showMessage: function (state) {
    if (state == WinLoseState.win) {
      HangmanGame.noteTextElement.classList.add("win-text");
      HangmanGame.noteTextElement.classList.remove("lose-text");
      if (HangmanGame.maxGuessCount == HangmanGame.guessCount) {
        HangmanGame.noteTextElement.innerText = "اي ياولا الحلاوة والشطارة دي جبتها من اول مرة, اكيد حظ.🥳😂";
      } else if (HangmanGame.guessCount - 1 == 0) {
        HangmanGame.noteTextElement.innerText = "ياه للاسف انت فزت بس كان فاضلك واحدة بس وتخسر 😤 يلا مش مهم شكل كده حظك حلو 🤭";
      } else {
        HangmanGame.noteTextElement.innerText = "مبروك, بس مستواك ممكن يتطور عن كدا حاول كتير يمكن ييجي منك 🤪😝";
      }
    } else {
      HangmanGame.noteTextElement.classList.remove("win-text");
      HangmanGame.noteTextElement.classList.add("lose-text");

      if (HangmanGame.correctGuess.length <= 0)
        HangmanGame.noteTextElement.innerText =
          "مش عارف اجيبهالك ازاي, بس انت خسرت وحتي مجبتش ولا حرف صح 😡 انا فقدت الامل فيك 😖, بلاش تحاول تاني 👊";
      else if (HangmanGame.correctGuess.length == HangmanGame.maxGuessCount - 1)
        HangmanGame.noteTextElement.innerText = "ياراجل, انت فاضلك واحدة بس وتفوز 😑, مش مهم حاول مره تانيه انت ذكي 🤭";
      else HangmanGame.noteTextElement.innerText = "انا قدرت اخسرك 😜, حاول تاني كده وهتخسر تاني 🤣";

      const rightWordElement = document.createElement("span");
      rightWordElement.classList.add("win-text");

      // show the word
      HangmanGame.noteTextElement.innerText += "\n";
      rightWordElement.innerText = `الكلمة الصحيحة هي [${HangmanGame.word}]`;
      HangmanGame.noteTextElement.appendChild(rightWordElement);
    }
  },
};

export default HangmanGame;
