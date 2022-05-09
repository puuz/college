/**
 * @file FactorialFractions.java
 * 
 * @brief Evaluates top and bottom for each fraction then adds and outputs the value.
 * 
 * Evaluates an expression for each top half from least to greatest then
 * for each bottom half it computes each factorial from greatest to least, at the
 * end it'll add each fraction up and output it.
 * 
 * @author Sam Farris
 * @date 2/16/2022
 */
package part2;
import java.lang.Math;
import java.util.Scanner;

public class FactorialFractions {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of x for the equation: ");
        double x = sc.nextDouble();
        System.out.println("Enter the number of fractions that should be added: ");
        int num = sc.nextInt();
        sc.close();
        double[] topNums = computeTop(x, num);
        int[] bottomNums = computeBottom(num);
        double y = 0;
        for (int i = 0; i < num; i++) {
            y += topNums[i] / bottomNums[i];
        }
        System.out.println("The value of y is " + y);
    }
    /**
     * @brief Computes the top half for each fraction from least to greatest using the
     * input of x from the user.
     * 
     * Computes the top half for each fraction from least to greatest using the
     * input of x from the user.
     *
     * @param num The number of evaluated numbers to compute from least to greatest
     *
     * @return int[] The evaluated numbers computed in an array from least to greatest
     */
    public static double[] computeTop(double x, int num) {
        double[] topNums = new double[num];
        for (int i = 1; i <= num; i++) {
            topNums[i - 1] = Math.pow(x + (i * i), i);
        }
        return topNums;
    }
    /**
     * @brief Computes factorial numbers from greatest to least in an array
     * the number of times that's in the num param.
     * 
     * Computes factorial numbers from greatest to least in an array
     * the number of times that's in the num param.
     *
     * @param num The number of factorials to compute from greatest to least
     *
     * @return int[] The factorial numbers computed in an array from greatest to least
     */
    public static int[] computeBottom(int num) {
        int[] bottomNums = new int[num];
        int index = 0;
        for (int i = num; i > 0; i--) {
            int factorial = 1;
            for (int j = 2; j <= i; j++) {
                factorial *= j;
            }
            bottomNums[index++] = factorial;
        }
        return bottomNums;
    }
}