package logic;

public class Client {
    private float balance;
    private String name;
    private int accountType;

    public Client(int balance, String name, int accountType) {
        this.balance = balance;
        this.name = name;
        this.accountType = accountType;
    }

    public String acType(int i) {
        return switch (i) {
            case 1:
                yield "Checking";

            case 2:
                yield "Savings";

            default:
                yield "null";
        };
    }

    public float getBalance() {
        return balance;
    }

    public void setBalance(float balance) {
        this.balance = balance;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAccountType() {
        return accountType;
    }

    public void setAccountType(int accountType) {
        this.accountType = accountType;
    }

}
