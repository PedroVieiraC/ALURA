import java.util.Scanner;

import static java.lang.System.exit;

public class Game {

    Guess guess = new Guess();
    Scanner scanner = new Scanner(System.in);

    private int reader;

    public void welcome() {
        System.out.println("""
                Welcome to number guesser game!
                (1) Start game
                (2) How to play
                (3) Quit game
                """);
        reader = scanner.nextInt();

        switch (reader) {
            case 1:
                starter();
                break;
            case 2:
                rules();
                break;
            case 3:
                exit(1);
                break;

        }
    }

    public void starter() {
        System.out.println("""
                Choose the difficulty:
                (1) Easy
                (2) Medium
                (3) Hard
                """);
        int reader = scanner.nextInt();
        int tryes = guess.tryesQuant(reader)-1;
        System.out.println(guess.tryesQuant(reader)-1);

        //System.out.println(" The number is " + guess.getNumber());
        System.out.println("first try: ");
        int guesst = scanner.nextInt();

        while (tryes != 0) {
            if (guess.guesser(guesst)) {
                endgame(1);
                break;
            } else {
                System.out.println("wrong answer, try again:");

                if(guess.range(guesst)) System.out.println("The try was bigger than the number");
                else System.out.println("The try was lower than the number");

                System.out.println("You have " + tryes + " tries");

                guesst = scanner.nextInt();



                tryes--;

            }

        }
        endgame(0);
    }

    public void rules() {
        System.out.println("""
                How does the game works?
                You will have 3 difficult to choose:
                (1) easy: 5 tries;
                (2) medium: 3 tries;
                (3) hard: 1 try;
                The game base is to guess the random number generated. To help you, the game says
                if your guess are higher or lower than the number.
                enter any key to back to menu;
                """);
        welcome();
    }

    public void endgame(int ref) {
        if (ref == 1) System.out.println("You won!!!");

        System.out.println("The number was: "+ guess.getNumber());

        System.out.println("""
                Play again?
                    (1) Yes;
                    (2) no;
                """);

        int pa = scanner.nextInt();
        if(pa == 1) {
            guess = new Guess();
            welcome();
        }
        else exit(1);

        }
    }


