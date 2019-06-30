import java.lang.Integer;

public class binary {

    public binary(){}

    // lists out integers and their binary counterparts up to a given limit
    public void listBinary(int limit){
        for (int i = 0; i < limit; i++) {
            if (i % 3 == 0){
                System.out.println("                    " + i + " is: " + Integer.toBinaryString(i));
            } else{
                System.out.println(i + " is: " + Integer.toBinaryString(i));
            }
        }
    }
}
