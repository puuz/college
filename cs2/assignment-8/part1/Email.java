package part1;

public class Email extends Document {
	private String sender;
	private String recipient;
	private String title;
	/**
	 * @brief returns the sender property on email object
	 * @return the sender property on email object
	 */
	public String getSender() {
		return this.sender;
	}
	/**
	 * @brief returns the recipient property on email object
	 * @return the recipient property on email object
	 */
	public String getRecipient() {
		return this.recipient;
	}
	/**
	 * @brief returns the title property on email object
	 * @return the title property on email object
	 */
	public String getTitle() {
		return this.title;
	}
	/**
	 * @brief setter for sender property on email object
	 * @param sender The new sender to assign to the sender property
	 */
	public void setSender(String sender) {
		this.sender = sender;
	}
	/**
	 * @brief setter for recipient property on email object
	 * @param recipient The new recipient to assign to the recipient property
	 */
	public void setRecipient(String recipient) {
		this.recipient = recipient;
	}
	/**
	 * @brief setter for title property on email object
	 * @param title The new title to assign to the title property
	 */
	public void setTitle(String title) {
		this.title = title;
	}
	/**
	 * @brief resolve abstract method from the parent to return the property lengths
	 * @return amount of characters in the sender, recipient, title, and text properties
	 */
	public int fileLength() {
		return this.sender.length() + this.recipient.length() + this.title.length() + this.getText().length();
	}
}