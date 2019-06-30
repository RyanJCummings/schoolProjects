
public class Coffee implements Comparable {

    private double price;
    private String color;
    private String distributor;

    public Coffee(double price, String color, String distributor){
        this.price = price;
        this.color = color;
        this.distributor = distributor;
    }


    /* Compares attributes of two Coffee Nodes and returns either -1 or 0. */
    @Override
    public int compareTo(Object coffee){
        Coffee other_coffee = (Coffee) coffee;
        if (this.price < other_coffee.price){
            return -1;
        }
        else if (this.price == other_coffee.price){
            if (distributor.compareTo(other_coffee.distributor) < 0){
                return -1;
            }
            else if (distributor.compareTo(other_coffee.distributor) == 0){
                if (color.compareTo(other_coffee.color) < 0){
                    return -1;
                }
                else if (color.compareTo(other_coffee.color) == 0) {
                    return 0;
                }
                else return 1;
            }
            else return 1;
        }
        else return 1;
    }


     /* Overrides toString() to show data contained in Coffee Nodes rather than memory locations. */
    public String toString(){
        return "Price: " + price + "\n" + "Color: " + color + "\n" + "Company/Distributer: " + distributor + "\n\n";
    }
}
