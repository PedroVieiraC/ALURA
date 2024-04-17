package ifa;
import logic.Client;
import logic.Control;

public class Main {
    static Client Jorge = new Client(15250,"Jorge", 1);
    static Control control = new Control(Jorge);
    static Welcome welcome = new Welcome(control,Jorge);
    public static void main(String[] args) {
        welcome.start();

    }

}