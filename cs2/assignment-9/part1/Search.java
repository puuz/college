package part1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Search {
	public static final String FILE_NAME = "UniqueIntegers.txt";
	private static ArrayList<Integer> numbers = new ArrayList<Integer>();
	public static void main(String args[]) {
		System.out.println("Starting Array: " + Search.numbers);
		Search.fillArrayFromFile();
		System.out.println("Filled Array: " + Search.numbers);
		Search.sortArray();
		System.out.println("Sorted Array: " + Search.numbers + "\n");
		Scanner inStd = new Scanner(System.in);
		System.out.println("Enter an integer to search for");
		while (!inStd.hasNextInt()) {
			System.out.println("That's not an integer, please re-enter");
			if (inStd.hasNextLine()) inStd.nextLine();
		}
		Integer key = inStd.nextInt();
		inStd.close();
		System.out.println("\nSequential Search: " + Search.sequentialSearch(key));
		System.out.println("Recursion Binary Search: " + Search.recursionBinarySearch(key, 0, Search.numbers.size() - 1));
		System.out.println("Binary Search: " + Search.binarySearch(key));
	}
	/**
	 * @brief fills the numbers array with the unique integers read in from file name
	 */
	public static void fillArrayFromFile() {
		try {
			Scanner inFile = new Scanner(new File(Search.FILE_NAME));
			while (inFile.hasNextInt()) {
				Search.numbers.add(inFile.nextInt());
				if (!inFile.hasNextLine()) break;
				inFile.nextLine();
			}
			inFile.close();
		} catch (FileNotFoundException error) {
			System.out.println("The file name (" + Search.FILE_NAME + ") wasn't found");
		}
	}
	/**
	 * @brief sorts the numbers array in ascending order
	 */
	public static void sortArray() {
		Integer outter;
		Integer inner;
		for (int i = 0; i < Search.numbers.size() - 1; i++) { 
			for (int j = i + 1; j < Search.numbers.size(); j++) {
				outter = Search.numbers.get(i);
				inner = Search.numbers.get(j);
				if (outter > inner) {
					Search.numbers.set(i, inner);
					Search.numbers.set(j, outter);
				}
			}
		}
	}
	/**
	 * @brief performs a sequential search
	 * @param key The number to search for in the numbers array
	 * @return whether the key exists in the numbers array
	 */
	public static boolean sequentialSearch(Integer key) {
		for (int i = 0; i < Search.numbers.size(); i++) {
			if (Search.numbers.get(i) == key) return true;
		}
		return false;
	}
	/**
	 * @brief performs a binary search using recursion
	 * @param key The number to search for in the numbers array
	 * @param low The index for the lower side of the array
	 * @param high The index for the higher side of the array
	 * @return whether the key exists in the numbers array
	 */
	public static boolean recursionBinarySearch(Integer key, int low, int high) {
		if (low <= high) {
			int middle = low + (high - low) / 2;
			Integer middleKey = Search.numbers.get(middle);
			if (middleKey == key) return true;
			if (middleKey < key) return Search.recursionBinarySearch(key, middle + 1, high);
			return Search.recursionBinarySearch(key, low, middle - 1);
		}
		return false;
	}
	/**
	 * @brief performs a binary search using a while loop
	 * @param key The number to search for in the numbers array
	 * @return whether the key exists in the numbers array
	 */
	public static boolean binarySearch(Integer key) {
		int low = 0;
		int high = Search.numbers.size() - 1;
		int middle;
		Integer middleKey;
		while (low <= high) {
			middle = low + (high - low) / 2;
			middleKey = Search.numbers.get(middle);
			if (middleKey == key) return true;
			if (middleKey < key) low = middle + 1;
			else high = middle - 1;
		}
		return false;
	}
}