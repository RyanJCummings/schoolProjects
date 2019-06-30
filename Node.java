public class Node<E> {
    private E data;
    private Node<E> left;
    private Node<E> right;

    public Node(E data){
        this.data = data;
        this.left = null;
        this.right = null;
    }

    // Getters and Setters
    public void setLeft(Node<E> whichNode){
        this.left = whichNode;
    }

    public void setRight(Node<E> whichNode){
        this.right = whichNode;
    }

    public void setData(E newData){
        data = newData;
    }

    public E getData(){
        return data;
    }

    public Node<E> getLeft(){
        return left;
    }

    public Node<E> getRight(){
        return right;
    }
}
