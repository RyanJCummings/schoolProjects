/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package outlab4;

/**
 *
 * @author ryancummings
 */
public class CircularLinkedList {
    Node first;
    Node last;
    
    public CircularLinkedList(){
        first = null;
        last = null;   
        int size = 0;
    }
    public boolean isEmpty(){
        return first == null;
    }
    public void insertFirst(){}
    public void insertLast(){}
    public void kTraverse(int num){}
    public void mTraverse(int num){}
}
