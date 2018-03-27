/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package outlab4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author ryancummings
 */
public class Outlab4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Node k;
        Node m;
        Scanner fileIn = null;
        Scanner console = new Scanner(System.in);

        System.out.println("Please enter a valid input file");
        try {
            fileIn = new Scanner(new File(console.next()));
        } catch (FileNotFoundException e) {
            System.out.println("Error reading file");
        }
        while (fileIn.hasNextLine()) {
            String x = fileIn.nextLine();
            String[] words = x.split(" ");
            int N = Integer.parseInt(words[0]);
            int cw = Integer.parseInt(words[1]);
            int cc = Integer.parseInt(words[2]);
            CircularLinkedList poliList = new CircularLinkedList(N, cw, cc);

                // while (poliList != null) {
                k = poliList.kTraverse(cw);
                m = poliList.mTraverse(cc);

                System.out.println(k.getData());
                System.out.println(m.getData());
            
            if (k.getData() != m.getData()) {
                poliList.delete(k);
                poliList.delete(m);
            }
            //}
            //System.out.println(last.getData());

            /*for(int i = 0; i < words.length; i++){
               System.out.println(words[i]);
           }*/
        }

    }

}
