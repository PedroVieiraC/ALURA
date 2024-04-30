package ifa;

import java.util.Scanner;

import logic.*;

import static java.lang.System.exit;

public class Welcome {
    private Control control = new Control(null);
    private Client client = new Client(0, null, 0);

    private boolean shows = true;

    private Scanner scan = new Scanner(System.in);

    public Welcome(Control control, Client client) {
        this.control = control;
        this.client = client;
    }

    public void start() {
        welcomePrinter(client, shows);
        int a = scan.nextInt();
        float b;
        switch (control.menu(a)) {
            case 1:
                shows = !shows;
                break;
            case 2:
                transferPrinter();
                b = scan.nextFloat();
                if (control.call(2, b)) {
                    while (control.call(2, b)) {
                        transferError();
                        transferPrinter();
                        b = scan.nextFloat();
                    }
                }
                ;
                break;
            case 3:
                receivePrinter();
                b = scan.nextFloat();
                control.call(3, b);
                break;
            case 4:
                control.close();
                break;
            case 5:
                notValid();
                start();

        }
        ;

        start();
    }

    public void welcomePrinter(Client client, boolean balanceControl) {
        System.out.println("******************************");
        System.out.println("Welcome to your bank account!");
        System.out.println("Name:" + client.getName());
        System.out.println("account type: " + client.acType(client.getAccountType()));
        if (balanceControl) System.out.println("balance: ***");
        else System.out.println("balance: " + client.getBalance());
        System.out.println("******************************");
        menuPrinter();
    }

    public void notValid(){
        System.out.println("Invalid option");
    }
    public void menuPrinter() {
        System.out.println("""
                Choose an option:
                (1) Consult balance;
                (2) Transfer money;
                (3) receive money;
                (4) exit;
                """);
    }

    public void transferPrinter() {
        System.out.println("How much do you want to transfer? ");

    }

    public void receivePrinter() {
        System.out.println("How much do you want to receive? ");
    }

    public void transferError() {
        System.out.println("You doesn't have enough money");
        System.out.println("negated transfer");
    }


}
