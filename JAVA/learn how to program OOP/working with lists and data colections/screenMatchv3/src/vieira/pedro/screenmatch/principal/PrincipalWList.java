package vieira.pedro.screenmatch.principal;

import vieira.pedro.screenmatch.calculus.Calculator;
import vieira.pedro.screenmatch.model.Movie;
import vieira.pedro.screenmatch.model.Serie;
import vieira.pedro.screenmatch.model.Title;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;

public class PrincipalWList {
    public static void main(String[] args) {

        Movie topGun = new Movie("Top Gun", 1988, false, 142);
        Serie you = new Serie("You", 2016, true, 0, 4, true, 10, 52);
        Movie filmeDoPaulo = new Movie("Dogville", 2003, false, 200);
        Calculator calculator = new Calculator();

        ArrayList<Title> titleArray = new ArrayList<>();
        titleArray.add(topGun);
        titleArray.add(filmeDoPaulo);
        titleArray.add(you);

        titleArray.forEach(title -> calculator.include(title));
        titleArray.forEach(title -> System.out.println(title.getRate()));
        System.out.println(titleArray.toString() + "\nTotal time: " +calculator.getTotalTime() + " minutes");

        ArrayList<String> findArtist = new ArrayList<>();
        findArtist.add("Wagner Moura");
        findArtist.add("Adam Sandler");
        findArtist.add("Caio Castro");


        Collections.sort(findArtist);
        Collections.sort(titleArray);

        System.out.println(findArtist);
        System.out.println(titleArray);
        titleArray.sort(Comparator.comparing(Title::getLaunchYear));
        System.out.println(titleArray);
    }
}
