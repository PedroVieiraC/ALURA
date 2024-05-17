package vieira.pedro.module;

public class Music extends Audio{
    private String album;
    private String singer;
    private String gender;

    public Music(String album, String singer, String gender) {
        this.album = album;
        this.singer = singer;
        this.gender = gender;
    }

    public String getAlbum() {
        return album;
    }

    public String getSinger() {
        return singer;
    }

    public String getGender() {
        return gender;
    }

}
