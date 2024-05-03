package vieira.pedro.principal;

import vieira.pedro.module.Music;
import vieira.pedro.module.Podcast;

public class Main {
    public static void main(String[] args) {

       Music music = new Music("Dots","Leep","Trap");
        Podcast podcast = new Podcast("intelig","alienx");
        for (int i = 0; i < 50; i++) {
            music.listen();
            music.listen();
            music.like();
        }

        for (int i = 0; i < 30; i++) {
            podcast.listen();
            podcast.listen();
            podcast.listen();
            podcast.listen();
            podcast.like();
        }

        System.out.println("music plays: " + music.getPlays() + " music likes: " + music.getLikes() + " rate: " + music.getRate());
        System.out.println("pod plays: " + podcast.getPlays() + " pod likes: " + podcast.getLikes() + " rate: " + podcast.getRate());
    }
}