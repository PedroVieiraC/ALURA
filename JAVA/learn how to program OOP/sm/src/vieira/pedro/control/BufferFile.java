package vieira.pedro.control;

import com.google.gson.FieldNamingPolicy;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import vieira.pedro.model.Title;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class BufferFile {
    public void writer(List<Title> titles) throws IOException {
        Gson gson = new GsonBuilder().setFieldNamingPolicy(FieldNamingPolicy.UPPER_CAMEL_CASE).setPrettyPrinting().create();
        FileWriter write = new FileWriter("movies.txt");
        write.write(gson.toJson(titles));
        write.close();
    }

    public void wjson(){
        Gson gson = new GsonBuilder().setFieldNamingPolicy(FieldNamingPolicy.UPPER_CAMEL_CASE).create();

    }
}
