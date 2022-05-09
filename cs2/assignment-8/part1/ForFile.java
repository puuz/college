package part1;

public class ForFile extends Document {
	private String pathname;
	/**
	 * @brief returns the pathname property on forfile object
	 * @return the pathname property on forfile object
	 */
	public String getPathname() {
		return this.pathname;
	}
	/**
	 * @brief setter for pathname property on forfile object
	 * @param pathname The new pathname to assign to the pathname property
	 */
	public void setPathname(String pathname) {
		this.pathname = pathname;
	}
	/**
	 * @brief overriding parents method to also return pathname property
	 * @returns the parent and pathname properties on forfile object
	 */
	public String toString() {
		return super.toString() + ",\n" + "{\n\tpathname: " + this.pathname + "\n}";
	}
	/**
	 * @brief overriding parents method to also compare the pathname property
	 * @param file The forfile object to compare to this object
	 * @return whether the passed forfile object equals this object
	 */
	public boolean equals(ForFile file) {
		return super.equals(file) && this.pathname.equals(file.pathname);
	}
	/**
	 * @brief resolve abstract method from the parent to return the text length
	 * @return amount of characters in the text property
	 */
	public int fileLength() {
		return this.getText().length();
	}
}