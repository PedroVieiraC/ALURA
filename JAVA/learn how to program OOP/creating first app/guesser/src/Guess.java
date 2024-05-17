import java.util.Random;

public class Guess {
    private int number = new Random().nextInt(100);;

    public int getNumber() {
        return number;
    }

    public int tryesQuant(int t){
        return switch (t) {
            case 2 -> 3;
            case 3 -> 1;
            default -> 5;
        };
    }

    public boolean guesser(int guess){
        return guess == number;
    }

    public boolean range(int guess){ return guess > number;}
}
