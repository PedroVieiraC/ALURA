package vieira.pedro.module;

public class Prefer {
    public String rate(Audio audio){
        if(audio.rateMedia() == 10) return "Top listen now!" ;
        if(audio.rateMedia() == 8) return "A lot of people likes";
        if(audio.rateMedia() == 6) return "Some people listen to";
        if(audio.rateMedia() == 4) return "An exotic kind of";
        if(audio.rateMedia() == 2) return "Bad rated";
    return null;
    }

}
