/**
 * @file Log.java
 * 
 * @brief Holds data for a log that is read from a file.
 * 
 * Holds data for a log containing a description, time, duration
 * date, and priority of the log. Also gives access to get the priority
 * and a formatted string of the log to print out.
 * 
 * @author Sam Farris
 * @date 3/3/2022
 */

package part1;
import java.util.Scanner;

public class Log {
	/** Description of the log read from logfile-1.txt */
    private String description;
    /** Time of the log read from logfile-1.txt */
    private String time;
    /** Duration of the log read from logfile-1.txt */
    private String duration;
    /** Date of the log read from logfile-1.txt */
    private String date;
    /** Priority of the log read from logfile-1.txt */
    private int priority;
    /**
     * @brief Constructor for log class to assign properties.
     * 
     * Constructor for log class to assign properties with the input stream
     * of logfile-1.txt. This also means that creating a new Log object means
     * that there is still at least 4 more lines need to be read from the file.
     * 
     * @param inputLogs The input stream on the logfile-1.txt file.
     */
    public Log(Scanner inputLogs) {
        description = inputLogs.nextLine();
        time = inputLogs.nextLine();
        duration = inputLogs.nextLine();
        date = inputLogs.nextLine();
        priority = Integer.parseInt(inputLogs.nextLine());
    }
    /**
     * @brief Gets the priority number of the log.
     * 
     * Gets the priority number of the log.
     * 
     * @return int The priority number of the log.
     */
    public int getPriority() {
        return priority;
    }
    /**
     * @brief Formats the log data into a string.
     * 
     * Formats the log data held in the log object to a formatted
     * string to print to the output stream.
     * 
     * @param logNum The log number when it's being printed with the other
     * logs to the output stream.
     * 
     * @return String The formatted string from the log object.
     */
    public String getLog(int logNum) {
        return "-".repeat(15) + "\n"
        	+ "Task " + logNum + "\n"
            + "description: " + description + "\n"
            + "Time: " + time + "\n"
            + "Duration: " + duration + "\n"
            + "Date: " + date + "\n"
            + "Priority: " + priority;
    }
}