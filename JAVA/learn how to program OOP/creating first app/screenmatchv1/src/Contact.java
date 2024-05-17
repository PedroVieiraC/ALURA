import java.util.Scanner;

public class Contact {
    public class contact {
        public contact() {
        }

        public static void main(String[] args) {
            Scanner read = new Scanner(System.in);
            System.out.println("Who is your favourite movie?");
            String favMovie = read.nextLine();
            System.out.println(favMovie);
        }
    }

}
