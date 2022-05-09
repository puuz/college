package part1;

public abstract class Document {
	private String text;
	public Document() {
		this.text = "";
	}
	public Document(String text) {
		this.text = text;
	}
	/**
	 * @brief returns the text property on document object
	 * @return the text property on document object
	 */
	public String getText() {
		return this.text;
	}
	/**
	 * @brief setter for text property on document object
	 * @param text The new text to assign to the text property
	 */
	public void setText(String text) {
		this.text = text;
	}
	/**
	 * @brief overriding parents method to only return text property
	 * @returns the text property on document object
	 */
	public String toString() {
		return "{\n\ttext: " + this.text + "\n}";
	}
	/**
	 * @brief overriding parents method to compare the text property
	 * @param document The document object to compare to this object
	 * @return whether the passed document object equals this object
	 */
	public boolean equals(Document document) {
		return this.text.equals(document.text);
	}
	/**
	 * @brief abstract method for the childs to get property lengths
	 * @return how many characters are in the properties of the object
	 */
	public abstract int fileLength();
}