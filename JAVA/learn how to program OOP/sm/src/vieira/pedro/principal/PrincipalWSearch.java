package vieira.pedro.principal;

import vieira.pedro.control.ApiConsult;
import vieira.pedro.control.BufferFile;
import vieira.pedro.exception.ConversionExcept;
import vieira.pedro.model.Title;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PrincipalWSearch {
    public static void main(String[] args) throws IOException, InterruptedException {

        ApiConsult api = new ApiConsult();
        Scanner scanner = new Scanner(System.in);
        String find = " ";
        BufferFile bf = new BufferFile();

        List<Title> titles = new ArrayList<>();

        while (!find.equalsIgnoreCase("exit")) {
            System.out.println("Digite um filme: ");
            find = scanner.nextLine();

            if(find.equalsIgnoreCase("exit")) break;
            try {

                Title mytitle = api.omdbToTitle(find);

                System.out.println(mytitle);


                titles.add(mytitle);

            } catch (NumberFormatException nfe) {
                System.out.println("error in: " + nfe.getMessage());
            } catch (IllegalArgumentException iae) {
                System.out.println("error in search");
            } catch (ConversionExcept ce) {
                System.out.println(ce.getMessage());
            }
        }
        bf.writer(titles);
        System.out.println(titles);

    }
}
