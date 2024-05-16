package vieira.pedro.control;

import com.google.gson.FieldNamingPolicy;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import vieira.pedro.model.Title;
import vieira.pedro.model.TitleOmdb;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.Scanner;

public class ApiConsult {

    public String finder(String find) throws IOException, InterruptedException {

        String url = "http://www.omdbapi.com/?t=" + find.replace(" ", "+") + "&apikey=7d5b7fbc";

        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder().uri(URI.create(url)).build();

        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        String json = response.body();
        return json;

    }

    public Title omdbToTitle(String find) throws IOException, InterruptedException {
        Gson gson = new GsonBuilder().setFieldNamingPolicy(FieldNamingPolicy.UPPER_CAMEL_CASE).create();

        TitleOmdb title = gson.fromJson(finder(find), TitleOmdb.class);

        return new Title(title);

    }


    public ApiConsult() throws IOException, InterruptedException {
    }
}
