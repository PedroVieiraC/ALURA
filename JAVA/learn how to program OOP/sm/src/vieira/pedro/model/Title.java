package vieira.pedro.model;

import com.google.gson.annotations.SerializedName;
import vieira.pedro.exception.ConversionExcept;

public class Title implements Comparable<Title> {
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

    public Title(TitleOmdb title) {
        this.name = title.title();
        if(title.year().length() > 4){
            throw new ConversionExcept("Cant write the year, more than 4 caracters");
        }
        this.launchYear = Integer.valueOf(title.year());
        this.time = Integer.valueOf(title.runtime().substring(0,2));

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

    public void rating(double rate) {
        this.rate += rate;
        rateQuantity++;
    }

    public double getRating() {
        return rate / rateQuantity;
    }

    @Override
    public String toString() {
        return ("Title: " + this.getName() + " (" + this.getLaunchYear() + ")"
                + " runtime: " + time + " minutes")
                ;
    }


    @Override
    public int compareTo(Title o) {
        return this.getName().compareTo(o.getName());
    }

}
