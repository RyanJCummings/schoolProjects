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
       Scanner fileIn = null;
       try{
           fileIn = new Scanner(new File("input.txt"));
       }catch(FileNotFoundException e){
           System.out.println("Error reading file");
       }
       while(fileIn.hasNextLine()){
           String x = fileIn.nextLine();
           String [] words = x.split(",");
           for(int i = 0; i < words.length; i++){
               System.out.println(words[i]);
           }
       }
       
    }
    
}
