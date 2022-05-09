/**
 * @file App.java
 * 
 * @brief Reads tasks from file and formats data to console if authorized.
 * 
 * Reads tasks from logfile-2.txt and formats the data to output stream if
 * the executer authorizes with the correct password that is held in the
 * passwords-1.txt file.
 * 
 * @author Sam Farris
 * @date 3/10/2022
 */

package part1;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class App {
    public static void main(String args[]) throws FileNotFoundException {
        if (!authorize()) return;
        Robot robot = new Robot();
        robot.readTasks();
        robot.sortTasks();
        robot.printTasks();
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
        Scanner passwords = new Scanner(new File("passwords-1.txt"));
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
}