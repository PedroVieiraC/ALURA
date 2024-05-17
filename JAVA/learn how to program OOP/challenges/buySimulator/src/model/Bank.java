package model;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;

public class Bank {
    Card card = new Card(400, 2000);

    ArrayList<Buy> buys = new ArrayList<>();

    public void getBuys() {
        Collections.sort(buys);
        System.out.println("You bought: " + buys);
        System.out.println("Current balance: " + card.balance + "\nCurrent limit: " + card.limit);
    }


    public void payment(int i, double value, String name) {
        if (i == 1) {
            //credit(value);
            if (credit(value)) {
                Buy buy = new Buy(name, value);
                buys.add(buy);
            }
        }

        if (i == 2) {
            //debit(value);
            if (debit(value)) {
                Buy buy = new Buy(name, value);
                buys.add(buy);
            }
        }
    }

    public boolean debit(double spent) {
        if (card.balance - spent >= 0) card.balance -= spent;
        else {
            System.out.println("Invalid operation;\nNot enough money");
            return false;
        }
        return true;
    }

    public boolean credit(double spent) {
        if (card.limit - spent >= 0) {
            card.limit -= spent;
            card.bill += spent;
        } else {
            System.out.println("Not enough limit");
            return false;
        }
        return true;
    }

}
