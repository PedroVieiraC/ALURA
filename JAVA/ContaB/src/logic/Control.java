package logic;

import static java.lang.System.exit;

public class Control {

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

    public float balance(Client client) {
        return client.getBalance();
    }

    public void transfer(Client client, float value) {
        client.setBalance(client.getBalance() - value);
    }

    public void receive(Client client, float value) {
        client.setBalance(client.getBalance() + value);
    }

    public void close() {
        exit(1);
    }
}
