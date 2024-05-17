package vieira.pedro.module;

public class Podcast extends Audio{
    private String host;
    private String description;

    public Podcast(String host, String description) {
        this.host = host;
        this.description = description;
    }

    public String getHost() {
        return host;
    }

    public String getDescription() {
        return description;
    }
}
