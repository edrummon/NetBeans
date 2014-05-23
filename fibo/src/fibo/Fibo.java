package fibo;

/**
 *
 * @author Instinct
 */
public class Fibo {

    public static String fibonacci(long n) {
        long temp;
        if (n == 1) {
            return "1, 1";
        } else {
            String s = "1, 1, ";
            long counter = 0;
            for (long i = 1, j = 2; j < n;) {
                if (counter == 0)
                    s += j;
                else
                    s = s + ", " + j;
                temp = j;
                j += i;
                i = temp;
                counter++;
                if (counter == 5) {
                    s += "\n";
                    counter = 0;
                }
            }
            return s;
        }
    }
    
    public static void main(String[] args) {
        System.out.println(fibonacci(1000000000000000000l)); //1 quintillion
    }
    
}
