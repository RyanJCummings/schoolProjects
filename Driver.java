public class Driver {

    public static void main(String[] Argv){
       TreeManager<Coffee> tree = new TreeManager<>();
       Node temp = new Node<>(new Coffee(12.00, "brown", "Folgers"));
       Node temp2 = new Node<>(new Coffee(11.00, "Tan", "Starbucks"));
       Node temp3 = new Node<>(new Coffee( 9.00, "dark", "City Brew"));
       tree.addFirst(temp);
       tree.addFirst(temp2);
       tree.addFirst(temp3);

       tree.preOrder(temp);
       //tree.preOrder(temp2);
       //tree.preOrder(temp3);

      /* tree.postOrder(temp);
       tree.postOrder(temp2);
       tree.postOrder(temp3);

       tree.inOrder(temp);
       tree.inOrder(temp2);
       tree.inOrder(temp3);*/

    }
}
