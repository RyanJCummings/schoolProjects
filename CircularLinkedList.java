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

    Node k;
    Node m;
    Node first;
    Node last;
    private int size = 0;

    public CircularLinkedList(int listSize, int cw, int cc) {
        int n = listSize;
        int clockwise = cw;
        int counterclock = cc;
        last = null;
        first = null;
        
        for (int i = 1; i <= listSize; i++) {
            insert(i);
        }
    }

    public int getSize() {
        return size;
    }
    
    public Node getFirst(){
        return first;
    }
    
    public void setFirst(Node temp){
        first = temp;
    }
    public boolean isEmpty() {
        return last.getNext() == null;
    }

    public void insert(int data) {
        if (last == null) {
            last = new Node(data);
            last.setNext(last);
            last.setPrevious(last);
            first = last;
            
        }
        else{
            Node temp = new Node(data); //creates temporary node
            last.setNext(temp); // moves next pointer to temp node
            temp.setPrevious(last); //sets new node's previous to last
            //first.setPrevious(temp);
            last = last.getNext(); //moves last pointer to new node
            first.setPrevious(last); // sets first's prev pointer to last
            
        }
    }
    public void delete(Node whichNode){
        if (isEmpty() == true){}    
        else{
            //whichNode = whichNode.getPrevious();
            whichNode.getPrevious().setNext(whichNode.getNext());
            System.out.println(whichNode.getData());
        }
    }
    
    public Node kTraverse(int kNum) {
        /*k.setPrevious(last);
        k.setNext(first.getNext());*/
        k = first;
        for (int i = 0; i < kNum; i++) {
            k = k.getNext();
        }
        return k;
    }

    public Node mTraverse(int mNum) {
        m = first;
        for (int i = 0; i < mNum; i++) {
            m = m.getPrevious();  
        }
        return m;
    }
}
