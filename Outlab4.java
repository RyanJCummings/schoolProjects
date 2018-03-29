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

            if (N == 0) {
                break;

            } else {
                CircularLinkedList poliList = new CircularLinkedList(N, cw, cc);
              
                while (poliList.isEmpty() == false) {
                    k = poliList.kTraverse(cw);
                    m = poliList.mTraverse(cc);
                    System.out.println("printing after round of deletion");
                    poliList.printList();
                    poliList.delete(k);
                    poliList.delete(m);
                }

            }

        }

    }
}
