package vieira.pedro.screenmatch.calculus;

import vieira.pedro.screenmatch.model.*;

public class Calculator {
    private int totalTime;

    public int getTotalTime() {
        return totalTime;
    }

    public void include(Title title){
        this.totalTime += title.getTime();
    }
}
