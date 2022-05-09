/**
 * @file MyFactorial.java
 *
 * @brief Computes the factorial for the
 * number that was inputted.
 * 
 * Computes the factorial for the
 * number that was inputted.
 * 
 * @author Sam Farris
 * @date 2/10/2022
 */
package part2;
import java.util.Scanner;

public class MyFactorial {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a positive integer to get it's factorial: ");
        int inputNum = sc.nextInt();
        int factorialNum = 1;
        for (int i = 2; i <= inputNum; i++) {
            factorialNum *= i;
        }
        System.out.println("The factorial of " + inputNum + " is " + factorialNum);
    }
}