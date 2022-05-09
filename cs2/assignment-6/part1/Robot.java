/**
 * @file Robot.java
 * 
 * @brief Holds data for the tasks read from a file.
 * 
 * Holds data for the tasks containing a description, time, duration
 * date, and priority of the task. Also gives access to add, print, and
 * sort the tasks in ascending order.
 * 
 * @author Sam Farris
 * @date 3/10/2022
 */

package part1;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Robot {
	/** tasks array of task objects */
    private Task[] tasks;
    /**
     * @brief Constructor for robot class to assign tasks property.
     * 
     * Constructor for robot class to assign tasks property.
     */
    public Robot() {
    	this.tasks = new Task[4];
    }
	/**
     * @brief Prints the all the tasks in format.
     * 
     * Prints the tasks that are held in the tasks array in format by looping over
     * the tasks and getting them in format and appending them to the formatted string.
     */
    public void printTasks() {
        String formattedTasks = "\nNumber of the tasks " + this.tasks.length + "\n";
        for (int i = 0; i < this.tasks.length; i++) {
        	formattedTasks += this.tasks[i].getTask(i + 1) + "\n";
        }
        System.out.println(formattedTasks);
    }
    /**
     * @brief Reads and adds tasks to the tasks array.
     * 
     * Reads and adds tasks to the tasks array. Which is done by reading 4 lines
     * from the logfile-2.txt file then assigning the properties correctly.
     */
    public void readTasks() throws FileNotFoundException {
    	Scanner inputLogs = new Scanner(new File("logfile-2.txt"));
        int tasks = 0;
        while (inputLogs.hasNextLine()) {
        	Task task = new Task(inputLogs);
            this.tasks[tasks++] = task;
        }
    }
    /**
     * @brief Sorts the tasks in ascending order.
     * 
     * Sorts the tasks from the tasks array in ascending order based on
     * the priority number in the task object.
     */
    public void sortTasks() {
        Task outter;
        Task inner;
        for (int i = 0; i < this.tasks.length; i++) {
            for (int j = i + 1; j < this.tasks.length; j++) {
                outter = this.tasks[i];
                inner = this.tasks[j];
                if (outter.getPriority() > inner.getPriority()) {
                    this.tasks[i] = inner;
                    this.tasks[j] = outter;
                }
            }
        }
    }
}
