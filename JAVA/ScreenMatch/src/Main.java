import vieira.pedro.screenmatch.calculus.Calculator;
import vieira.pedro.screenmatch.calculus.Recomends;
import vieira.pedro.screenmatch.model.Episode;
import vieira.pedro.screenmatch.model.Movie;
import vieira.pedro.screenmatch.model.Serie;

public class Main {
    static Movie movie = new Movie("Top Gun", 1988, false, 142);
    static Movie movide = new Movie("Top Gun", 1988, false, 142);
    static Serie you = new Serie("You", 2016, true, 0, 4, true, 10, 52);

    public static void main(String[] args) {
        movie.showDetails();
        movie.rating(9);
        movie.rating(3);
        System.out.println(movie.getRating());

        System.out.println(you.getTime());

        Calculator calculator = new Calculator();
        calculator.include(movie);
        calculator.include(movide);
        //calculator.include(you);
        System.out.println(calculator.getTotalTime());

        Recomends recomends = new Recomends();
        recomends.filter(movie);
        recomends.filter(you);
        Episode ep = new Episode(1, "in a cold", you, 00);
        recomends.filter(ep);

    }
}