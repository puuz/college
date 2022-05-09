package part1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DocumentApp {
	private static String titleKeyword = "title";
	private static String senderKeyword = "sender";
	private static String recipientKeyword = "recipient";
	public static void main(String args[]) {
		Scanner inStd = new Scanner(System.in);
		Scanner inFile = null;
		System.out.println("Enter the name of the file:");
		boolean fileRead = false;
		do {
			try {
				String fileName = inStd.nextLine();
				if (!fileName.endsWith(".txt")) fileName += ".txt";
				inFile = new Scanner(new File(fileName));
				if (!inFile.hasNextLine()) {
					System.out.println("The document is empty");
					break;
				}
				String title = inFile.nextLine();
				if (!title.toLowerCase().startsWith(DocumentApp.titleKeyword)) {
					ForFile forFile = new ForFile();
					forFile.setPathname(fileName);
					String text = DocumentApp.parseText(inFile, title + "\n");
					if (text == null) break;
					forFile.setText(text);
					DocumentApp.askForKeyword(forFile, inStd);
					break;
				}
				Email email = new Email();
				email.setTitle(title.substring(DocumentApp.titleKeyword.length()).trim());
				String sender = DocumentApp.parseEmail(inFile, DocumentApp.senderKeyword);
				if (sender == null) break;
				String recipient = DocumentApp.parseEmail(inFile, DocumentApp.recipientKeyword);
				if (recipient == null) break;
				email.setSender(sender);
				email.setRecipient(recipient);
				String text = DocumentApp.parseText(inFile, "");
				if (text == null) break;
				email.setText(text);
				DocumentApp.askForKeyword(email, inStd);
				break;
			} catch (FileNotFoundException error) {
				System.out.println("Incorrect file name, enter a valid one:");
			}
		} while (!fileRead);
		if (inFile != null) inFile.close();
		inStd.close();
	}
	/**
	 * @brief prompts for the keyword and outputs the results for the keyword
	 * @param document The document object or an object that derives from it
	 * @param inStd The standard input stream
	 */
	private static void askForKeyword(Document document, Scanner inStd) {
		String type;
		if (document instanceof ForFile) type = "file";
		else if (document instanceof Email) type = "email";
		else type = "document";
		System.out.println("The " + type + " file has been parsed which is "
		+ document.fileLength() + " characters long\nSo, what keyword do you want to search for?");
		String keyword = inStd.nextLine();
		if (DocumentApp.containsKeyword(document, keyword)) {
			System.out.println("The keyword " + keyword + " was FOUND in the " + type + " :)");
		} else {
			System.out.println("The keyword " + keyword + " was NOT found in the " + type + " :(");
		}
	}
	/**
	 * @brief checks if the text property contains the passed keyword
	 * @param document The document object to check for the text property
	 * @param keyword The keyword to check in the text property on the document object
	 * @return whether the keyword was found in the text property on the document object
	 */
	private static boolean containsKeyword(Document document, String keyword) {
		return document.getText().contains(keyword);
	}
	/**
	 * @brief parses the text in a email or forfile type of document
	 * @param inFile The input file stream
	 * @param text The primary text to start with
	 * @return the text that was parsed from the file or null if empty
	 */
	private static String parseText(Scanner inFile, String text) {
		if (text.equals("") && !inFile.hasNextLine()) {
			System.out.println("The document's text is empty");
			return null;
		}
		while (inFile.hasNextLine()) {
			text += inFile.nextLine() + "\n";
		}
		return text;
	}
	/**
	 * @brief parses the header information for the email object
	 * @param inFile The input file stream
	 * @param type The type of header information to parse
	 * @return the header information that was parsed from the file or null if empty or incorrect
	 */
	private static String parseEmail(Scanner inFile, String type) {
		if (!inFile.hasNextLine()) {
			System.out.println("The email doesn't have a " + type);
			return null;
		}
		String parsed = inFile.nextLine();
		if (!parsed.toLowerCase().startsWith(type)) {
			System.out.println("The email doesn't have a " + type);
			return null;
		}
		return parsed.substring(type.length()).trim();
	}
}