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
public class Node {
    private int num;
    private Node next, previous;
    
    public Node(){}
    public Node(int number){
         num = number;
         System.out.println(this.getData());
         
    }
    public void setNext(Node temp){
        next = temp;
    }
    public Node getNext(){
        return next;
    }
    public void setPrevious(Node temp){
        previous = temp;
    }
    public Node getPrevious(){
        return previous;
    }
    public int getData(){
        return num;
    }
}
