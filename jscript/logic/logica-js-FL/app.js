let range = 99;
let sortedNumbers = [];
let secretNum = createSecretnum();
let tryes = 1;
main();

function main() {
  start();
}

function showText(tag, text) {
  responsiveVoice.speak(text, "Brazilian Portuguese Female", { rate: 1.2 });
  let campo = document.querySelector(tag);
  campo.innerHTML = text;
}

function start() {
  showText("h1", "Secret number game");

  let ptext = `Choose a number between 1 and ${range}`;

  showText("p", ptext);
}

function createSecretnum() {
  let num = parseInt(Math.random() * 100 + 1);

  let maximum = sortedNumbers.length;
  if (maximum == range) {
    sortedNumbers = [];
  }

  if (sortedNumbers.includes(num)) {
    return createSecretnum();
  }
  sortedNumbers.push(num);
  console.log(sortedNumbers);
  return num;
}

function seeGuess() {
  let guess = document.querySelector("input").value;
  if (guess == secretNum) {
    showText("h1", "Guessed!");
    let tryesMessage = `you right guessed the secret number with ${tryes} tryes`;
    showText("p", tryesMessage);
    document.getElementById("reiniciar").removeAttribute("disabled");
  } else {
    if (guess > secretNum) showText("p", "the secret number is lower");
    else {
      showText("p", "the secret number is bigger");
    }
    tryes++;
    cleaner();
  }
}

function cleaner() {
  guess = document.querySelector("input");
  guess.value = "";
}

function newGame() {
  document.getElementById("reiniciar").setAttribute("disabled", true);
  secretNum = createSecretnum();
  cleaner();
  start();
  tryes = 1;
}
