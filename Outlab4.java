/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package outlab4;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
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
        String fileName = "output.txt";
        PrintWriter writer = null;

        System.out.println("Please enter a valid input file");
        try {
            fileIn = new Scanner(new File(console.next()));
        } catch (FileNotFoundException e) {
            System.out.println("Error reading file");
        }

        try {
            writer = new PrintWriter(fileName);
        } catch (FileNotFoundException e) {
            System.out.println("Output Error");
        }

        while (fileIn.hasNextLine()) {
            String x = fileIn.nextLine();
            String[] words = x.split(" ");
            int N = Integer.parseInt(words[0]);
            int cw = Integer.parseInt(words[1]);
            int cc = Integer.parseInt(words[2]);
            
            writer.println("Program 4");
            writer.println("---------");
            writer.println("");
            writer.println("N = " + N + ", k = " + cw + ", m = " + cc);
            writer.println("");
            writer.println("Output");
            writer.println("------");

            if (N == 0) {
                break;

            } else {
                CircularLinkedList poliList = new CircularLinkedList(N, cw, cc);

                while (poliList.isEmpty() == false) {
                    k = poliList.kTraverse(cw);
                    m = poliList.mTraverse(cc);
                    writer.print(k.getData());
                    writer.print(" ");
                    writer.println(m.getData());
                   // poliList.printList();
                    poliList.delete(k);
                    poliList.delete(m);
                }

            }

        }
        writer.println("End of Program 4");
        writer.close();
    }
}
