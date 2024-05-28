alert("welcome to guess game");

let secretnum = 29, guess, tryes=0;

while(secretnum != guess){
guess = prompt("choose a number");
if (secretnum == guess) {
  alert(`Nice! you guessed the secret number! ${secretnum}`);
} else if (guess > secretnum) {
  alert("your guess is bigger than the secret number");
} else {
  alert("your guess is lower than the secret number");
}
tryes++;
}
alert(`tryes quantity ${tryes}`);
// while(tryes!=0){
//     guess = prompt("choose a number");
//     if (secretnum == guess) {
//       alert(`Nice! you guessed the secret number! ${secretnum}`);
//     } else if (guess > secretnum) {
//       alert("your guess is bigger than the secret number");
//     } else {
//       alert("your guess is lower than the secret number");
//     }
//     tryes--;
// }
