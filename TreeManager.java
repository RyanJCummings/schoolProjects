public class TreeManager<E extends Comparable> {

    private Node<E> rootNode;

    /*
     * Constructor for Binary Search Tree without balancing on node removal
     */
    public TreeManager() {
        rootNode = null;
    }

    public void addFirst(Node<E> firstNode) {
        rootNode = addNode(rootNode, firstNode);
    }

    /*
     * Adds node in proper position to maintain Binary Search Tree
     */
    public Node<E> addNode(Node<E> rootNode, Node<E> newNode) {
        if (rootNode == null) {
            rootNode = newNode;
            return rootNode;
        }
        // if new node < root node, recurse left
        else if (newNode.getData().compareTo(rootNode.getData()) < 0) {
            if (rootNode.getLeft() == null) {
                rootNode.setLeft(newNode);
            } else {
                addNode(rootNode.getLeft(), newNode);
            }
        }
        // if new node > root node, recurse right
        else if (newNode.getData().compareTo(rootNode.getData()) > 0) {
            if (rootNode.getRight() == null) {
                rootNode.setRight(newNode);
            } else {
                addNode(rootNode.getRight(), newNode);
            }
        }
        // if new node is the same as root, do nothing
        else if (newNode.getData().compareTo(rootNode.getData()) == 0) {
            return rootNode;
        }
        return rootNode;
    }

    // stores root of the tree and calls removeNode
    public void delete(Node<E> deleteNode){
          rootNode = removeNode(rootNode, deleteNode);
    }
    // recursive method to identify and delete node to be removed
    public Node<E> removeNode(Node<E> rootNode, Node<E> killNode) {
        // base case : Tree is empty
        if (rootNode == null){
            return rootNode;
        }
        // if killNode.getData < rootNode.getData() recur down left side of tree
        if (killNode.getData().compareTo(rootNode.getData()) < 0){
            rootNode.setLeft(removeNode(rootNode.getLeft(), killNode));
        }
        // if killNode.getData() > rootNode.getData() recur down right side of tree
         else if (killNode.getData().compareTo(rootNode.getData()) > 0) {
            rootNode.setRight(removeNode(rootNode.getRight(), killNode));
        }
        // once killNode data has been found delete node
        else {
            // if killNode has neither left nor right child
            if (rootNode.getLeft() == null && rootNode.getRight() == null){
                return null;
            }
            // if killNode has right child but no left child
            else if (rootNode.getLeft() == null){
                return rootNode.getRight();
            }
            // if killNode has left child but no right child
            else if (rootNode.getRight() == null){
                return rootNode.getLeft();
            }
            // if killNode has both left and right children
            else {
                Node<E> min = getMin(rootNode.getRight());
                rootNode.setData(min.getData());
                rootNode.setRight(removeNode(rootNode.getRight(), min));
            }
        }
        return rootNode;
    }
    // gets minimum valued node
    public Node<E> getMin(Node<E> node){
        if (node.getLeft() != null){
            return getMin(node.getLeft());
        }
        return node;
    }

    /* Traversal methods */

    public void inOrder(Node<E> node) {
        if (node == null) {
            return;
        } else {
            inOrder(node.getLeft());
            System.out.print(node.getData());
            inOrder(node.getRight());
        }
    }

    public void postOrder(Node<E> node) {
        if (node == null) {
            return;
        } else {
            postOrder(node.getLeft());
            postOrder(node.getRight());
            System.out.print(node.getData());
        }
    }

    public void preOrder(Node<E> node) {
        if (node == null) {
            return;
        } else {
            System.out.print(node.getData());
            preOrder(node.getLeft());
            preOrder(node.getRight());
        }
    }

}
