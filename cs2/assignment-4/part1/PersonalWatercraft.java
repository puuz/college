/**
 * @file PersonalWatercraft.java
 * 
 * @brief Prompts for car information then formats and outputs it.
 * 
 * Asks for information on the number of cars requested. Then
 * organizes the cars by it's inputted price when outputted.
 * 
 * @author Sam Farris
 * @date 2/24/2022
 */
package part1;
import java.util.Scanner;

public class PersonalWatercraft {
    public static String[] makes;
    public static String[] models;
    public static int[] numOfSeatsArr;
    public static boolean[] hasBackupCamArr;
    public static double[] prices;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("How many cars are there?");
        while (!sc.hasNextInt()) {
            System.out.println("The answer should be a whole number...");
            sc.nextLine();
        }
        int numOfCars = sc.nextInt();
        sc.nextLine();

        makes = new String[numOfCars];
        models = new String[numOfCars];
        numOfSeatsArr = new int[numOfCars];
        hasBackupCamArr = new boolean[numOfCars];
        prices = new double[numOfCars];

        for (int i = 0; i < numOfCars; i++) {
            addCar(sc, i);
        }
        sc.close();
        
        String tempStr;
        int tempInt;
        boolean tempBoolean;
        double tempDouble;
        for (int i = 0; i < numOfCars - 1; i++) {
            for (int j = 0; j < numOfCars - i - 1; j++) {
                if (prices[j] > prices[j + 1]) {
                    tempStr = makes[j];
                    makes[j] = makes[j + 1];
                    makes[j + 1] = tempStr;

                    tempStr = models[j];
                    models[j] = models[j + 1];
                    models[j + 1] = tempStr;

                    tempInt = numOfSeatsArr[j];
                    numOfSeatsArr[j] = numOfSeatsArr[j + 1];
                    numOfSeatsArr[j + 1] = tempInt;

                    tempBoolean = hasBackupCamArr[j];
                    hasBackupCamArr[j] = hasBackupCamArr[j + 1];
                    hasBackupCamArr[j + 1] = tempBoolean;

                    tempDouble = prices[j];
                    prices[j] = prices[j + 1];
                    prices[j + 1] = tempDouble;
                }
            }
        }
        System.out.println("\n" + "-".repeat(25));
        for (int i = 0; i < numOfCars; i++) {
            System.out.println("Make\t\t: " + makes[i]);
            System.out.println("Model\t\t: " + models[i]);
            System.out.println("Number of seats\t: " + numOfSeatsArr[i]);
            System.out.println("Backup camera\t: " + hasBackupCamArr[i]);
            System.out.println("Car Price\t: " + prices[i]);
            System.out.println("-".repeat(25));
        }
    }
    /**
     * @brief Prompts for car information and adds to the static arrays.
     * 
     * Prompts for car information while also handling invalid data types.
     * Once it gets a valid data type for the piece of information it'll
     * add it to the needed array in the correct position.
     * 
     * @param sc The input stream.
     * @param i The index of where the data should be put in the array.
     */
    public static void addCar(Scanner sc, int i) {
        System.out.println("What is the make of car #" + (i + 1) + "?");
        makes[i] = sc.nextLine();

        System.out.println("What is the model of car #" + (i + 1) + "?");
        models[i] = sc.nextLine();

        System.out.println("What is the number of seats in car #" + (i + 1) + "?");
        while (!sc.hasNextInt()) {
            System.out.println("The answer should be a whole number...");
            sc.nextLine();
        }
        numOfSeatsArr[i] = sc.nextInt();
        sc.nextLine();

        System.out.println("Is there a backup camera in car #" + (i + 1) + "?");
        while (!sc.hasNextBoolean()) {
            System.out.println("The answer should be true or false...");
            sc.nextLine();
        }
        hasBackupCamArr[i] = sc.nextBoolean();
        sc.nextLine();

        System.out.println("What is the price of car #" + (i + 1) + "?");
        while(!sc.hasNextDouble()) {
            System.out.println("The answer should be a number...");
            sc.nextLine();
        }
        prices[i] = sc.nextDouble();
        sc.nextLine();
    }
}