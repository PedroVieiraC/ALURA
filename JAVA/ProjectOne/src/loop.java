import java.util.Scanner;

public class loop {
    public static void main(String[] args) {

        Scanner read = new Scanner(System.in);
        double averageRating = 0;


        for (int i = 0; i < 3; i++) {
            System.out.println("What is your rating of:?");
            int rate = read.nextInt();
            averageRating += rate;
        }

        System.out.println(averageRating/3);
    }
}



