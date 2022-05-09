/**
 * @file ArrayProgramming.java
 * 
 * @brief Creates 2 arrays with random values and creates another array
 * with computed values based on the 2 arrays and prints the 3 arrays.
 * 
 * Creates 2 arrays that are 2 dimensional with random double values from 0 to 15,
 * then multiplies each element within each array of that array to create another
 * 2 dimensional array with those values. Then finally prints the 3 arrays.
 * 
 * @author Sam Farris
 * @date 2/24/2022
 */
package part3;
import java.util.Random;

public class ArrayProgramming {
    public static void main(String args[]) {
        double[][] x = new double[3][4];
        double[][] y = new double[4][5];
        fillArray(x);
        fillArray(y);
        double[][] z = multiplyArrays(x, y);
        System.out.println("\n");
        printArray(x);
        printArray(y);
        printArray(z);
    }
    /**
     * @brief Fills array with random values.
     * 
     * Fills 2 diemnsional array with random double values from 0 to 15.
     * 
     * @param arr The 2 dimensional array to fill.
     */
    public static void fillArray(double[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                Random rand = new Random();
                //SI told me to do it like this because eclipse wasn't allowing rand.nextDouble(15 or 15.0)
                arr[i][j] = rand.nextInt(15) + rand.nextDouble();
            }
        }
    }
    /**
     * @brief Creates a new array based on the values in the 2 arrays.
     * 
     * Creates a new fixed size 2 dimensional array based on multipling
     * the elements together that's in the 2 inputted arrays.
     * 
     * @param x The first 2 diemnsional array to compute the new array.
     * @param y The second 2 diemnsional array to compute the new array.
     * 
     * @return double[][] The new 2 diemnsional array with the computed values.
     */
    public static double[][] multiplyArrays(double[][] x, double[][] y) {
        double[][] z = new double[3][4];
        for (int i = 0; i < z.length; i++) {
            for (int j = 0; j < z[i].length; j++) {
                z[i][j] = x[i][j] * y[i][j];
            }
        }
        return z;
    }
    /**
     * @brief Prints the array.
     * 
     * Prints the 2 diemnsional array with formatting of brackets.
     * 
     * @param arr The 2 diemnsional array to print.
     */
    public static void printArray(double[][] arr) {
        System.out.print("[ ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print("[ ");
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.print("] ");
        }
        System.out.print("]\n\n");
    }
}