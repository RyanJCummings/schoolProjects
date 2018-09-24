public class TreeManager<E extends Comparable> {

    private Node<E> rootNode, treeRoot;

    /*
     * Constructor for Binary Search Tree without balancing on node removal
     */
    public TreeManager() {
        rootNode = null;
        //rootNode = rootNode;
        // Node<E> current_root = rootNode;
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
            if (rootNode.getLeft() == null){
                rootNode.setLeft(newNode);
            }
            else {
                addNode(rootNode.getLeft(), newNode);
            }
        }
        // if new node > root node, recurse right
        else if (newNode.getData().compareTo(rootNode.getData()) > 0) {
            if (rootNode.getRight() == null){
                rootNode.setLeft(newNode);
            }
            else {
                addNode(rootNode.getRight(), newNode);
            }
        }
        // if new node is the same as root, do nothing
        else if (newNode.getData().compareTo(rootNode.getData()) == 0) {
            return rootNode;
        }
        return rootNode;
    }


    public void removeNode(Node<E> killNode){
        // to do
    }

   public void inOrder(Node<E> node){
        if (node == null){
            return;
        }
        else {
            inOrder(node.getLeft());
            System.out.print(node.getData());
            inOrder(node.getRight());
        }
   }

   public void postOrder(Node<E> node){
        if (node == null){
            return;
        }
        else {
            postOrder(node.getLeft());
            postOrder(node.getRight());
            System.out.print(node.getData());
        }
   }

   public void preOrder(Node<E> node){
        if (node == null) {
            return;
        }
        else {
            System.out.print(node.getData());
            preOrder(node.getLeft());
            preOrder(node.getRight());
        }
   }

}
