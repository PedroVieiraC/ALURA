import calculus.PayMachine;
import model.Bank;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int t;
        Bank bank = new Bank();
        PayMachine pay = new PayMachine();


        Scanner scan = new Scanner(System.in);
        do {
            System.out.println("Welcome!");

            System.out.println("what are you buying: ");
            String name = scan.next();

            System.out.println("What is the value of: ");
            double value = scan.nextDouble();

            System.out.println("""
                    What is the type of payment?
                    (1) credit;
                    (2) debit;
                    """);

            bank.payment(pay.buyType(scan.nextInt()), value, name);
            System.out.println("0 to exit, 1 to continue buying");
            t = scan.nextInt();
        } while (t != 0);

        bank.getBuys();
    }
}