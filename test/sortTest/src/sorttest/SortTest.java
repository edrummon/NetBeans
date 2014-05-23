package sorttest;

/**
 *
 * @author Instinct
 */
public class SortTest {

    public static int[] sort(int[] z) {
        int max = z[0], min = z[0], size = z.length, posMax = 0, posMin = 0, temp, count = 0, index = 0;
        boolean sorted = false;
        
        while (!sorted) {
            for (int i = index+1; i < size-1; i++) {
                if (max < z[i]) {
                    max = z[i];
                    posMax = i;
                }
                if (min > z[i]) {
                    min = z[i];
                    posMin = i;
                }
            }
            temp = z[index];
            z[index] = max;
            z[posMax] = temp;
            temp = z[size-1];
            z[size-1] = min;
            z[posMin] = temp;
            index++;
            count++;
            if (count == size-1)
                sorted = true;
        }
        System.out.println();
        for (int i = 0; i < size; i++) {
            System.out.print(z[i] + "  ");
        }
        System.out.println();
        return z;
        
    }
    
    public static void main(String[] args) {
        int[] x = {3, 17, 12, 504, 1, 99, 87, 212, 900, 9, 72};
        int[] sorted = sort(x);
        for (int i = 0; i < x.length; i++) {
            System.out.print(x[i] + "  ");
        }
        System.out.print("\n");
        for (int i = 0; i < sorted.length; i++) {
            System.out.print(sorted[i] + "  ");
        }
    }
}
