package vieira.pedro.calculus;

import vieira.pedro.model.*;

public class Calculator {
    private int totalTime;

    public int getTotalTime() {
        return totalTime;
    }

    public void include(Title title) {
        this.totalTime += title.getTime();
    }
}
