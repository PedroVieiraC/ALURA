package vieira.pedro.principal;

import java.util.ArrayList;

import vieira.pedro.model.*;
import vieira.pedro.principal.*;
import vieira.pedro.calculus.*;


public class Main {
    static Movie topGun = new Movie("Top Gun", 1988, false, 142);
    static Serie you = new Serie("You", 2016, true, 0, 4, true, 10, 52);
    static Movie filmeDoPaulo = new Movie("Dogville", 2003, false, 200);

    public static void main(String[] args) {
        //rate
        topGun.rating(9);
        topGun.rating(3);
        System.out.println("rate of topgun:" + topGun.getRating());

        //calculator of time in queue titles
        Calculator calculator = new Calculator();
        calculator.include(topGun);
        calculator.include(you);
        System.out.println(calculator.getTotalTime());

        //recomends list
        Recomends recomends = new Recomends();
        recomends.filter(topGun);
        recomends.filter(you);
        Episode ep = new Episode(1, "in a cold", you, 00);
        recomends.filter(ep);

        //arraylist of the movies in catalog
        ArrayList<Movie> movieArray = new ArrayList<>();
        movieArray.add(topGun);
        movieArray.add(filmeDoPaulo);

        System.out.println(topGun.toString());
        System.out.println(you.toString());

    }
}
