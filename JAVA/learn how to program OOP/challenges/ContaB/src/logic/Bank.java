package logic;

public class Bank {
    public float balance(Client client) {
        return client.getBalance();
    }

    public boolean showsBalance(){
        return false;
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

}
