import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        Scanner scanner = new Scanner(System.in);
        String cep = scanner.nextLine();

        try {
            FindCEP fc = new FindCEP();
            Address ad = fc.finder(cep);
            System.out.println(ad);
            FileGen fg = new FileGen();
            fg.genJson(ad);
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }
}