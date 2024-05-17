package model;

public class Buy implements Comparable<Buy>{
    String name;
    double value;

    public Buy(String name, double value) {
        this.name = name;
        this.value = value;
    }

    @Override
    public String toString() {
        return "Name: " + this.name + " value: " + this.value;
    }

    @Override
    public int compareTo(Buy o) {
        return Double.valueOf(this.value).compareTo(Double.valueOf(o.value));
    }
}
