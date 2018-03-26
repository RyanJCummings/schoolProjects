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
    Node last;
    private int size = 0;
    
    public CircularLinkedList(int listSize, int clockwise, int counterclock){
        int n = listSize;
        int k = n % clockwise;
        int m = n % counterclock;
        last = null;   
    }
    public int getSize(){
        return size;
    }
    public boolean isEmpty(){
        return last.getNext() == null;
    }
    public void insertFirst(){}
    public void insertLast(){
        if(size == 0){
            last = new Node();
        }
    }
    public void getNext(){}
    public void kTraverse(int num){}
    public void mTraverse(int num){}
}
