alert("welcome to guess game");

let secretnum, guess, tryes=1, range = 100;
secretnum = parseInt(Math.random() * range + 1);
alert(`${secretnum}`)



while(secretnum != guess){
guess = prompt(`choose a number between 1 and ${range}`);
if (secretnum == guess) {
    break;
} else if (guess > secretnum) {
    alert("your guess is bigger than the secret number");
} else {
    alert("your guess is lower than the secret number");
}
tryes++;
}
alert(`Nice! you guessed the secret number! ${secretnum} tryes quantity ${tryes}`);
