package ifa;
import logic.*;
import datas.*;
import logic.Client;

import static java.lang.System.exit;

public class Welcome {
    Control control = new Control();
    public void printer(Client client) {
        System.out.println("******************************");
        System.out.println("Welcome to your bank account!");
        System.out.println("Name:" + client.getName());
        System.out.println("account type: " + control.acType(client.getAccountType()));
        System.out.println("balance: " + client.getBalance());
        System.out.println("******************************");

        System.out.println("""
                Choose an option:
                (1) Consult balance;
                (2) Transfer money;
                (3) receive moeny;
                (4) exit;
                """);
    }

    public void menu(int i) {
        switch (i) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                exit(1);
            break;
        }
    }

}
