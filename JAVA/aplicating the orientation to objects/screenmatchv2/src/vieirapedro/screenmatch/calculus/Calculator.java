package vieirapedro.screenmatch.calculus;

import vieirapedro.screenmatch.model.*;

public class Calculator {
    private int totalTime;

    public int getTotalTime() {
        return totalTime;
    }

    public void setTotalTime(int totalTime) {
        this.totalTime = totalTime;
    }

    public void include(Title title){
        this.totalTime += title.getTime();
    }
}
