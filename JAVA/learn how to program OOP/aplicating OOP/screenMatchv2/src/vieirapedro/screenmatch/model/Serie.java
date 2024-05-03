package vieirapedro.screenmatch.model;

import vieirapedro.screenmatch.calculus.Classified;

public class Serie extends Title implements Classified {
    private int seasons;
    private boolean on;
    private int epbyseasons;
    private int minutesByEp;
    private int sees;

    public Serie(String name, int launchYear, boolean plan, int time, int seasons, boolean on, int epbyseasons, int minutesByEp) {
        super(name, launchYear, plan, time);
        this.seasons = seasons;
        this.on = on;
        this.epbyseasons = epbyseasons;
        this.minutesByEp = minutesByEp;
    }

    @Override
    public int getTime() {
        return seasons*epbyseasons*minutesByEp;
    }

    @Override
    public int getClassication() {
        if(sees>100) return 4;
        if(sees>50) return 2;
        return 1;
    }
}
