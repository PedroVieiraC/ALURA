package vieira.pedro.calculus;

public class Recomends {

    public void filter(Classified classified) {
        if (classified.getClassication() >= 4) System.out.println("It's one of the loved of moment");
        else if (classified.getClassication() >= 2) {
            System.out.println("Good rate in moment!");
        } else {
            System.out.println("puts in your queue to watch later");
        }
    }
}
