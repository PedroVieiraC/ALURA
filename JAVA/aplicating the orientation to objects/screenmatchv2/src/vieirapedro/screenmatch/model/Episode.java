package vieirapedro.screenmatch.model;

import vieirapedro.screenmatch.calculus.Classified;

public class Episode implements Classified {
    private int number;
    private String name;
    private Serie serie;
    private int totalSees;

    public Episode(int number, String name, Serie serie,int totalSees) {
        this.number = number;
        this.name = name;
        this.serie = serie;
        this.totalSees = totalSees;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Serie getSerie() {
        return serie;
    }

    public void setSerie(Serie serie) {
        this.serie = serie;
    }

    public int getTotalSees() {
        return totalSees;
    }

    public void setTotalSees(int totalSees) {
        this.totalSees = totalSees;
    }

    @Override
    public int getClassication() {
        if(totalSees > 100) return 4;
        return 2;
    }
}
