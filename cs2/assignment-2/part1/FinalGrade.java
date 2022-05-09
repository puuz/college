/**
 * @file FinalGrade.java
 *
 * @brief Computes the grade percentage and grade
 * letter for given scores on such assignments.
 *
 * Computes the grade percentage and grade
 * letter for given scores on such assignments.
 * It'll also ask if there needs to be another
 * grade computed after one is done.
 *
 * @author Sam Farris
 * @date 2/10/2022
 */
package part1;
import java.util.Scanner;
import java.lang.Math;

public class FinalGrade {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char execute = 'Y';
        while (execute == 'Y' || execute == 'y') {
            double midTerm1 = getInput(sc, 0, 15, "Mid Term 1");
            double midTerm2 = getInput(sc, 0, 15, "Mid Term 2");
            double finalExam = getInput(sc, 0, 20, "Final Exam");
            double assignments = getInput(sc, 0, 50, "Assignments");
            double grade = midTerm1 + midTerm2 + finalExam + assignments;
            String gradeLetter;
            if (grade < 0.6) {
                gradeLetter = "F";
            } else if (grade < 0.7) {
                gradeLetter = "D";
            } else if (grade < 0.8) {
                if (grade < 0.73) {
                    gradeLetter = "C-";
                } else if (grade < 0.78) {
                    gradeLetter = "C";
                } else {
                    gradeLetter = "C+";
                }
            } else if (grade < 0.9) {
                if (grade < 0.83) {
                    gradeLetter = "B-";
                } else if (grade < 0.88) {
                    gradeLetter = "B";
                } else {
                    gradeLetter = "B+";
                }
            } else {
                if (grade < 0.93) {
                    gradeLetter = "A-";
                } else {
                    gradeLetter = "A";
                }
            }
            System.out.println("The percentage is " + grade * 100 + "% and the grade is " + gradeLetter);
            System.out.println("Do you want to execute again? [Y/N] ");
            execute = sc.next().charAt(0);
        }
        System.out.println("Goodbye!");
    }
    /**
     * @brief Gets the input and evaluates the input
     * based on the required range and computes for grade in decimal form.
     *
     * Gets the input and evaluates the input
     * based on the required range and computes for grade in decimal form.
     * 
     * @param sc The scanner input stream to get inputs from.
     * @param lowest The lowest number allowed in the input.
     * @param highest The highest number allowed in the input.
     * @param inputType The input type to display what should be entered.
     *
     * @return value The value computed based on the highest score in decimal form.
     */
    public static double getInput(Scanner sc, int lowest, int highest, String inputType) {
    	System.out.println("Enter a value from " + lowest + " - " + highest + " for " + inputType + ": ");
    	double value = sc.nextDouble();
    	while (value < lowest || value > highest) {
        	System.out.println("Reenter a value from " + lowest + " - " + highest + " for " + inputType + ": ");
            value = sc.nextDouble();
        }
        return value / highest * (highest / 100.0);
    }
}