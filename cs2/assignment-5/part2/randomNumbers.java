/**
 * @file randomNumbers.java
 * 
 * @brief Creates random numbers in a file and organizes the numbers
 * in new files.
 * 
 * Creates random whole numbers from 1 to 500 and organizes them in 2 other
 * files which that being odd and even as well as printing all the prime
 * numbers to the output stream.
 * 
 * @date 3/3/2022
 * @author Sam Farris
 */

package part2;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Random;
import java.util.Scanner;

public class randomNumbers {
	public static void main(String args[]) throws FileNotFoundException {
		generate();
		printPrime();
		storeNumbers();
	}
	/**
	 * @brief Generates random numbers in a file.
	 * 
	 * Generates random numbers in the intData.txt file that is in the range
	 * from 1 and 500 while also all the numbers being integers.
	 * 
	 * @throws FileNotFoundException
	 */
	private static void generate() throws FileNotFoundException {
		PrintStream outputNumbers = new PrintStream(new File("intData.txt"));
		Random rand = new Random();
		for (int i = 0; i < 100; i++) {
			outputNumbers.println(rand.nextInt(500) + 1);	
		}
		outputNumbers.close();
	}
	/**
	 * @brief Prints the prime numbers read in the generated file.
	 * 
	 * Prints all the prime numbers that are held in the generated file
	 * that being the intData.txt file which is created with the generate method.
	 * 
	 * @throws FileNotFoundException
	 */
	private static void printPrime() throws FileNotFoundException {
		Scanner inputNumbers = new Scanner(new File("intData.txt"));
		int num;
		boolean isPrime = true;
		do {
			num = inputNumbers.nextInt();
			if (inputNumbers.hasNextLine()) {
				inputNumbers.nextLine();
			}
			//skip numbers 0 and 1 and ignore negatives
			if (num <= 1) continue;
			//start at 2 and module check by each number, if none remain to 0
			//then print line the number to the console
			for (int i = 2; i < num; i++) {
				if (num % i == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) System.out.println(num);
			//reset the boolean
			isPrime = true;
		} while (inputNumbers.hasNextInt());
		inputNumbers.close();
	}
	/**
	 * @brief Stores new numbers in new files from the generated file.
	 * 
	 * Stores odd numbers in the oddIntData.txt file and even numbers in
	 * the evenIntData.txt file which are read in from the intData.txt
	 * file which is made from the generate method.
	 * 
	 * @throws FileNotFoundException
	 */
	private static void storeNumbers() throws FileNotFoundException {
		Scanner inputNumbers = new Scanner(new File("intData.txt"));
		PrintStream outputOdds = new PrintStream(new File("oddIntData.txt"));
		PrintStream outputEvens = new PrintStream(new File("evenIntData.txt"));
		int num;
		do {
			num = inputNumbers.nextInt();
			if (inputNumbers.hasNextLine()) {
				inputNumbers.nextLine();
			}
			if (num % 2 == 1) {
				outputOdds.println(num);
			} else {
				outputEvens.println(num);
			}
		} while (inputNumbers.hasNextInt());
		inputNumbers.close();
		outputOdds.close();
		outputEvens.close();
	}
}