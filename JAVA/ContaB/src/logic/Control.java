package logic;

import static java.lang.System.exit;

public class Control {
    Client client = new Client();

    public Control(Client client) {
        this.client = client;
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

    public void menu(int i) {
        return switch (i) {
            case 1:
                balance(client);
                break;
            case 2:
                transfer(client);
                break;
            case 3:
                receive(client);
                break;
            case 4:
                exit(1);
                break;
    }

    public float balance(Client client) {
        return client.getBalance();
    }

    public boolean transfer(Client client, float value) {
        if ((client.getBalance() - value) > 0) {
            client.setBalance(client.getBalance() - value);
            return false;
        }
        return true;
    }

    public void receive(Client client, float value) {
        client.setBalance(client.getBalance() + value);
    }

    public void close() {
        exit(1);
    }
}
