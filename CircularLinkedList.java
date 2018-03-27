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

    public CircularLinkedList(int listSize, int clockwise, int counterclock) {
        int n = listSize;
        if (n > 0){
            int k = n % clockwise;
            int m = n % counterclock;
        }else{
            int k = clockwise;
            int m = counterclock;
        }
        last = null;
        
        for (int i = 1; i <= listSize; i++) {
            insert(i);
        }
    }

    public int getSize() {
        return size;
    }

    public boolean isEmpty() {
        return last.getNext() == null;
    }

    public void insert(int data) {
        if (last == null) {
            last = new Node(data);
            last.setNext(last);
            last.setPrevious(last);
        }
        else{
            last.setNext(new Node(data));
            last = last.getNext();
            
        }
    }

    public void kTraverse(int num) {
    }

    public void mTraverse(int num) {
    }
}
