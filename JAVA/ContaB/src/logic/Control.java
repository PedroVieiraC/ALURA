package logic;

import ifa.Welcome;

import static java.lang.System.exit;

public class Control {
    private Client client = new Client(0, null, 0);
    private Bank bank = new Bank();

    public boolean shows = true;

    public Control(Client client) {
        this.client = client;
    }

    public int menu(int i) {
        return switch (i) {
            case 1 -> 1;
            case 2 -> 2;
            case 3 -> 3;
            case 4 -> 4;
            default -> 5;
        };
    }

    public boolean call(int code, float value) {
        if (code == 2) {
            return bank.transfer(client, value);
        }
        if (code == 3) {
            bank.receive(client, value);
        }
    return true;
    }


public void close() {
    exit(1);
}
}
