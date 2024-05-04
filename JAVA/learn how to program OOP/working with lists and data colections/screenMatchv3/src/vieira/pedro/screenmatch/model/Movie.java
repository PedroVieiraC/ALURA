package vieira.pedro.screenmatch.model;

import vieira.pedro.screenmatch.calculus.Classified;

public class Movie extends Title implements Classified {
    public String director;

    public Movie(String name, int launchYear, boolean plan, int time) {

        super(name, launchYear, plan, time);
    }

    @Override
    public int getClassication() {
        return (int) getRate() / 2;
    }
}
