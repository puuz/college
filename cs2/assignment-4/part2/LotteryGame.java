/**
 * @file LotteryGame.java
 * 
 * @brief A lottery game that is played by guessing number that would
 * be in a set of 10 other numbers.
 * 
 * A lottery game that is played by guessing a single whole number
 * that is between 1 and 99 with 10 different winning numbers with the
 * same parameters. It'll then prompt the results once the number is guessed.
 * 
 * @author Sam Farris
 * @date 2/24/2022
 */
package part2;
import java.util.Random;
import java.util.Scanner;

public class LotteryGame {
    public static void main(String args[]) {
        int[] lotteryNumbers = new int[10];
        initialize(lotteryNumbers);
        generate(lotteryNumbers);
        Scanner sc = new Scanner(System.in);
        //this print statement needs to be outside of the input function
        //because of the way it's recalled based on input
        System.out.println("Enter a winning number between 1 and 99:");
        int selectedNumber = input(sc);
        if (check(lotteryNumbers, selectedNumber)) {
            System.out.println("Congrats, you won! Below is the rest of the winning numbers.");
        } else {
            System.out.println("Dang, you lost. Below is the rest of the winning numbers.");
        }
        printOut(sc, lotteryNumbers, selectedNumber);
        sc.close();
    }
    /**
     * @breif Checks if the num param is in the lotteryNumbers param.
     * 
     * Checks if the num param is in the lotteryNumbers param. It'll
     * return true if it is or false if it isn't.
     * 
     * @param lotteryNumbers The array to check if the value is in.
     * @param num The value to check if it's in the array.
     * 
     * @return boolean True if it's in the array or false otherwise.
     */
    public static boolean check(int[] lotteryNumbers, int num) {
        for (int i = 0; i < lotteryNumbers.length; i++) {
            if (lotteryNumbers[i] == num) return true;
        }
        return false;
    }
    /**
     * @breif Fills the lotteryNumbers array with random ints.
     * 
     * Fills the lotteryNumbers array with random ints between 1 and 99,
     * the lotteryNumbers array is provided in the params.
     * 
     * @param lotteryNumbers The array to fill random ints between 1 and 99 in.
     */
    public static void generate(int[] lotteryNumbers) {
        Random rand = new Random();
        for (int i = 0; i < lotteryNumbers.length; i++) {
            int num;
            do {
                num = rand.nextInt(99 - 1) + 1;
            } while (check(lotteryNumbers, num));
            lotteryNumbers[i] = num;
        }
    }
    /**
     * @brief Fills the lotteryNumbers array with 0.
     * 
     * Fills the lotteryNumbers array with 0, the lotteryNumbers array
     * is provided in the params.
     * 
     * @param lotteryNumbers The array to fill with 0.
     */
    public static void initialize(int[] lotteryNumbers) {
        for (int i = 0; i < lotteryNumbers.length; i++) {
            lotteryNumbers[i] = 0;
        }
    }
    /**
     * @brief Prompts for the number the user wants to use to try and win.
     * 
     * Prompts for the number the user wants to use to try and win. It'll
     * handle both invalid data types and invalid ranges by reprompting.
     * 
     * @param sc The input stream.
     * 
     * @return int The selected number chosen by the user.
     */
    public static int input(Scanner sc) {
        while (!sc.hasNextInt()) {
            System.out.println("The answer should be a whole number...");
            sc.nextLine();
        }
        int selectedNumber = sc.nextInt();
        sc.nextLine();
        if (selectedNumber < 1 || selectedNumber > 99) {
            System.out.println("The answer should be between 1 and 99...");
            selectedNumber = input(sc);
        }
        return selectedNumber;
    }
    /**
     * @brief Prints out the lotteryNumbers along with the selectedNumber.
     * 
     * Prints out the lotteryNumbers along with the selectedNumber.
     * 
     * @param sc The input stream.
     * @param lotteryNumbers The array of randomly generated winning numbers to print.
     * @param selectedNumber The selected number by the user.
     */
    public static void printOut(Scanner sc, int[] lotteryNumbers, int selectedNumber) {
        for (int i = 0; i < lotteryNumbers.length; i++) {
            System.out.print(lotteryNumbers[i] + " ");
        }
        System.out.print("- " + selectedNumber);
    }
}