package model;

import java.util.Scanner;

public class Card {
    double balance;
    double bill;
    double limit;

    public Card(double balance, double limit) {
        this.balance = balance;
        this.limit = limit;
    }

    public double getLimit() {
        return limit;
    }

    public Card(int balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public double bill() {
        return bill;
    }


}
