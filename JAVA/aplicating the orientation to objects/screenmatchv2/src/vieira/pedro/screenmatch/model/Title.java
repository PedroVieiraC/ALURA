package vieira.pedro.screenmatch.model;

public class Title {
    private String name;
    private int launchYear;
    private boolean plan;
    private double rate;
    private int rateQuantity;
    private int time;

    public Title(String name, int launchYear, boolean plan, int time) {
        this.name = name;
        this.launchYear = launchYear;
        this.plan = plan;
        this.time = time;
    }

    public String getName() {
        return name;
    }

    public int getLaunchYear() {
        return launchYear;
    }

    public boolean isPlan() {
        return plan;
    }

    public double getRate() {
        return rate;
    }

    public int getRateQuantity() {
        return rateQuantity;
    }

    public int getTime() {
        return time;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setLaunchYear(int launchYear) {
        this.launchYear = launchYear;
    }

    public void setPlan(boolean plan) {
        this.plan = plan;
    }

    public void setRate(double rate) {
        this.rate = rate;
    }

    public void setRateQuantity(int rateQuantity) {
        this.rateQuantity = rateQuantity;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public void showDetails() {
        System.out.println("br.com.alura.screenmatch.model.Movie name: " + name);
        System.out.println("Launch year: " + launchYear);
    }

    public void rating(double rate) {
        this.rate += rate;
        rateQuantity++;
    }

    public double getRating() {
        return rate / rateQuantity;
    }

}

