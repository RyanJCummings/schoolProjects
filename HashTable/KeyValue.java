import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

public class KeyValue {
    int key;
    String value;

    public KeyValue(int key, String value) {
        this.key = key;
        this.value = value;
    }

    public void setKey(int toSet){
        this.key = toSet;
    }

    public void setValue(String toSet){
        this.value = toSet;
    }

    public String getValue() {
        return value;
    }

    public int getKey() {
        return key;
    }

    public static void main(String[] argv) {
        KeyValue pair;
        KVArray hash = new KVArray();

        try {
            File inFile = new File("input.txt");
            Scanner readIn = new Scanner(inFile);
            while (readIn.hasNextLine()) {
                pair = new KeyValue(readIn.nextInt(), readIn.next());
                hash.hashMap(pair);
            }
            readIn.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }
    }
}

