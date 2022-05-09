/**
 * @file Task.java
 * 
 * @brief Holds data for a task that is read from a file.
 * 
 * Holds data for a task containing a description, time, duration
 * date, and priority of the task. Also gives access to get the priority
 * and a formatted string of the task to print out.
 * 
 * @author Sam Farris
 * @date 3/10/2022
 */

package part1;
import java.util.Scanner;

public class Task {
	/** Description of the task read from logfile-2.txt */
    private String description;
    /** Time of the task read from logfile-2.txt */
    private String time;
    /** Duration of the task read from logfile-2.txt */
    private String duration;
    /** Date of the task read from logfile-2.txt */
    private String date;
    /** Priority of the task read from logfile-2.txt */
    private int priority;
    /**
     * @brief Constructor for task class to assign properties.
     * 
     * Constructor for task class to assign properties with the input stream
     * of logfile-2.txt. This also means that creating a new task object means
     * that there is still at least 4 more lines need to be read from the file.
     * 
     * @param inputLogs The input stream on the logfile-2.txt file.
     */
    public Task(Scanner inputLogs) {
        this.description = inputLogs.nextLine();
        this.time = inputLogs.nextLine();
        this.duration = inputLogs.nextLine();
        this.date = inputLogs.nextLine();
        this.priority = Integer.parseInt(inputLogs.nextLine());
    }
    /**
     * @brief Gets the priority number of the task.
     * 
     * Gets the priority number of the task.
     * 
     * @return int The priority number of the task.
     */
    public int getPriority() {
        return this.priority;
    }
    /**
     * @brief Formats the task data into a string.
     * 
     * Formats the task data held in the task object to a formatted
     * string to print to the output stream.
     * 
     * @param taskNum The task number when it's being printed with the other
     * tasks to the output stream.
     * 
     * @return String The formatted string from the task object.
     */
    public String getTask(int taskNum) {
        return "-".repeat(15) + "\n"
        	+ "Task " + taskNum + "\n"
            + "description: " + this.description + "\n"
            + "Time: " + this.time + "\n"
            + "Duration: " + this.duration + "\n"
            + "Date: " + this.date + "\n"
            + "Priority: " + this.priority;
    }
}