package java.Repertoires;

import java.io.File;

public class Main {
    public static void main(String[] args) {
        for(File file : new File("toto").listFiles()){
            System.out.print(file.getName());
        }
    }
}