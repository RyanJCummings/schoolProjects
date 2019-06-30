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
    Node k;
    Node m;
    private int size = 0;
    int[] printArray = new int[3];

    public CircularLinkedList(int listSize, int cw, int cc) {
        int n = listSize;
        int clockwise = cw;
        int counterclock = cc;
        last = null;
        first = null;
        printArray[0] = n;
        printArray[1] = clockwise;
        printArray[2] = counterclock;
        
        for (int i = 1; i <= listSize; i++) {
            insert(i);
        }
    }
    
    public int[] getPrint(){
        return printArray;
    }
    
    public int getSize() {
        return size;
    }

    public Node getLast() {
        return last;
    }

    public void setLast(Node temp) {
        last = temp;
    }

    public Node getFirst() {
        return first;
    }

    public void setFirst(Node temp) {
        first = temp;
    }

    public boolean isEmpty() {
        return last == null;
    }

    public void insert(int data) {
        if (last == null) {
            last = new Node(data);
            last.setNext(last);
            last.setPrevious(last);
            first = last;

        } else {
            Node temp = new Node(data); //creates temporary node
            temp.setNext(first);
            last.setNext(temp); // moves next pointer to temp node
            temp.setPrevious(last); //sets new node's previous to last
            last = last.getNext(); //moves last pointer to new node
            first.setPrevious(last); // sets first's prev pointer to last
            k = first;
            m = last;
        }
    }

    public void delete(Node whichNode) {
        
        if (isEmpty() == true) {
            System.out.println("The list is empty.");
        } else if (last == first) {
            k = null;
            m = null;
            last = null;
            first = null;
        } else {
            if (whichNode == k) {
                k = k.getNext();
            }
            if (whichNode == m) {
               
                m = m.getPrevious();
            }
            if (whichNode == last) {
                last = last.getPrevious();
                last.setNext(first);
            }
            if (whichNode == first) {
                first = first.getNext();
            }
            whichNode.getPrevious().setNext(whichNode.getNext());
            whichNode.getNext().setPrevious(whichNode.getPrevious());

        }
    }

    public Node kTraverse(int kNum) {
        for (int i = 1; i < kNum; i++) {
            k = k.getNext();
        }
        
        return k;
    }

    public Node mTraverse(int mNum) {
        for (int i = 1; i < mNum; i++) {
            m = m.getPrevious();
        }
        
        return m;
    }

    public void printList() {
        Node current = new Node();
        current = first;
        do {
        
            current = current.getNext();
        } while (current != first);

    }
}
