package ifa;

import logic.*;
import datas.*;
import logic.Client;

import static java.lang.System.exit;

public class Welcome {
    public void start(CLient client, int a) {
        welcomePrinter(client, a);


    }

    public void welcomePrinter(Client client, int balanceControl) {
        System.out.println("******************************");
        System.out.println("Welcome to your bank account!");
        System.out.println("Name:" + client.getName());
        System.out.println("account type: " + control.acType(client.getAccountType()));
        if(balanceControl) System.out.println("balance: ***" );
        else System.out.println("balance: " + client.getBalance());
        System.out.println("******************************");
    }

    public void menuPrinter(){
        System.out.println("""
                Choose an option:
                (1) Consult balance;
                (2) Transfer money;
                (3) receive money;
                (4) exit;
                """);
    }

    public void transferPrinter(){
        System.out.println("How much do you want to transfer? ");


    }

    public void receivePrinter(){
        System.out.println("How much do you want to receive? ");
    }

    public void transferError(){
        System.out.println("You doesn't have enough money");
        System.out.println("negated transfer");
    }


}
