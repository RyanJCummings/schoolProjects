public class FizzBuzz {
    public static int factorial(int num){
        if (num == 0){
            return 1;
        } else {
            return num * factorial(num - 1);
        }

    }
    public static void main(String args[]){
       /* for (int i = 1; i <= 100; i++) {
            if (i % 3 == 0 && i % 5 == 0){
                System.out.println("FIZZBUZZ");
            }
            else if (i % 3 == 0) {
                System.out.println("Fizz");
            }
            else if (i % 5 == 0) {
                System.out.println("Buzz");
            }
            else {
                System.out.println(i);
            }
        }


        int f = factorial(5);
        System.out.println(f);*/

        binary bin = new binary();
        bin.listBinary(500);
    }
}
