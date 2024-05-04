package calculus;

public class PayMachine {
    public int buyType(int i) {
        return switch (i) {
            case 1 -> 1;
            case 2 -> 2;
            default -> throw new IllegalStateException("Unexpected value: " + i);
        };
    }


}
