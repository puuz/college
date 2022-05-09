/**
 * @file Logs.java
 * 
 * @brief Reads logs from file and formats data to console if authorized.
 * 
 * Reads logs from logfile-1.txt and formats the data to output stream if
 * the executer authorizes with the correct password that is held in the
 * passwords.txt file.
 * 
 * @author Sam Farris
 * @date 3/3/2022
 */

package part1;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Logs {
	/** Logs array of log objects */
    private static Log[] logs = new Log[4];
    public static void main(String args[]) throws FileNotFoundException {
        if (!authorize()) return;
        Scanner inputLogs = new Scanner(new File("logfile-1.txt"));
        int tasks = 0;
        while (inputLogs.hasNextLine()) addLog(inputLogs, tasks++);
        sortLogs();
        printLogs(tasks);
    }
    /**
     * @brief Adds a log to the logs array.
     * 
     * Adds a log to the logs array which is done by read 4 lines from the
     * logfile-1.txt file then assigning the properties correctly.
     * 
     * @param inputLogs The input stream on the logfile-1.txt file.
     * @param logNum The index to use in the logs array when assigning.
     */
    private static void addLog(Scanner inputLogs, int logNum) {
        Log log = new Log(inputLogs);
        logs[logNum] = log;
    }
    /**
     * @brief Asks executer to authorize
     * 
     * Asks executer to authorize with a password which is held in the
     * passwords.txt file, this means that it can be multiple passwords.
     * 
     * @return boolean Based on if the executer authorized correctly or not.
     * 
     * @throws FileNotFoundException If file isn't found
     */
    private static boolean authorize() throws FileNotFoundException {
        System.out.println("Password: ");
        Scanner console = new Scanner(System.in);
        String password = console.nextLine();
        Scanner passwords = new Scanner(new File("passwords.txt"));
        while (passwords.hasNextLine()) {
            if (password.equals(passwords.nextLine())) {
                console.close();
                passwords.close();
                return true;
            }
        }
        console.close();
        passwords.close();
        System.out.println("Incorrect password!");
        return false;
    }
    /**
     * @brief Prints the logs in format.
     * 
     * Prints the logs that are held in the logs array in format by looping over
     * the logs and getting them in format and appending them to the formatted string.
     * 
     * @param tasks The task/log number that is being printed to the output stream.
     */
    private static void printLogs(int tasks) {
        String formattedLogs = "\nNumber of the tasks " + tasks + "\n";
        for (int i = 0; i < logs.length; i++) {
            formattedLogs += logs[i].getLog(i + 1) + "\n";
        }
        System.out.println(formattedLogs);
    }
    /**
     * @brief Sorts the logs in ascending order.
     * 
     * Sorts the logs from the logs array in ascending order based on
     * the priority number in the log object.
     */
    private static void sortLogs() {
        Log outter;
        Log inner;
        for (int i = 0; i < logs.length; i++) {
            for (int j = i + 1; j < logs.length; j++) {
                outter = logs[i];
                inner = logs[j];
                if (outter.getPriority() > inner.getPriority()) {
                    logs[i] = inner;
                    logs[j] = outter;
                }
            }
        }
    }
}