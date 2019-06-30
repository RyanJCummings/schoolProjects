public class Driver {

    public static void main(String[] Argv){
       TreeManager<Coffee> tree = new TreeManager<>();
       Node test = new Node<>(new Coffee(12.00, "brown", "Folgers"));
       Node test2 = new Node<>(new Coffee(13.00, "Tan", "Starbucks"));
       Node test3 = new Node<>(new Coffee( 14.00, "dark", "City Brew"));
       Node test4 = new Node<>(new Coffee(10.00, "medium", "Hunter's Zesty Coffee"));
       Node test5 = new Node<>(new Coffee(8.00, "medium", "Hunter's Zesty Coffee"));
       Node test6 = new Node<>(new Coffee(10.00, "medium", "Hunter's Zesty Coffee"));
       Node test7 = new Node<>(new Coffee(18.00, "black", "Kopi Luac"));

       tree.addFirst(test);
       tree.addFirst(test2);
       tree.addFirst(test3);
       tree.addFirst(test4);
       tree.addFirst(test5);
       tree.addFirst(test6);
       tree.addFirst(test7);

       System.out.println("PreOrder Traversal:");
       tree.preOrder(test);
       System.out.println("InOrder Traversal:");
       tree.inOrder(test);
       System.out.println("PostOrder Traversal:");
       tree.postOrder(test);

       tree.delete(test4);
       tree.delete(test);
       tree.inOrder(test);
    }
}
