/**
 * @file ComputeRange.java
 * 
 * @brief Computes each number in the range
 * of the two inputed numbers for given formula.
 * 
 * Computes each number in the range
 * of the two inputed numbers for given formula.
 * 
 * @author Sam Farris
 * @date 2/10/2022
 */
package part3;
import java.util.Scanner;

public class ComputeRange {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of A: ");
    	int a = sc.nextInt();
        System.out.println("Enter the value of B: ");
        int b = sc.nextInt();
        while (a > b) {
        	System.out.println("A is greater than B, please reenter the value of A: ");
        	a = sc.nextInt();
            System.out.println("Reenter the value of B: ");
            b = sc.nextInt();
        }
        String results = "\nX\tY\n---\t---\n";
        for (int i = a; i <= b; i++) {
            results += i + "\t" + (7 * (i * i) + 4 * i - 4) + "\n";
        }
        System.out.println(results);
    }
}