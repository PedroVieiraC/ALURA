package vieira.pedro.module;

public class Audio {
    private String title;
    private int durationTime;
    private int plays;
    private int likes;

    private Prefer prefer = new Prefer();

    public void like(){
        this.likes++;
    }

    public void listen(){this.plays++;}

    public String getTitle() {
        return title;
    }

    public int getDurationTime() {
        return durationTime;
    }

    public int getPlays() {
        return plays;
    }

    public int getLikes() {
        return likes;
    }

    public int rateMedia(){
        if((this.getPlays()/this.getLikes()) < 1) return 10;
        if((this.getPlays()/this.getLikes()) < 2) return 8;
        if((this.getPlays()/this.getLikes()) < 3) return 6;
        if((this.getPlays()/this.getLikes()) < 4) return 4;
        if((this.getPlays()/this.getLikes()) < 5) return 2;
        return 0;
    }

    public String getRate(){
    return prefer.rate(this);

    }
}
