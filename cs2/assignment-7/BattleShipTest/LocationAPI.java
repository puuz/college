package BattleShipTest;

public interface LocationAPI {
	/**
	 * @brief checks if the yx is formatted correctly then sets it
	 * @param location The yx inputed from the user
	 * @return whether the location was set or not
	 */
	public boolean setLocation(String location);
	/**
	 * @brief picks a random location
	 */
	public void pick();
	/**
	 * @brief asks the user to input coordinates of the next shot
	 */
	public void fire();
	/**
	 * @brief prints location in format as y and x
	 */
	public void print();
	/**
	 * @brief formats the y and x for return value
	 * @return y and x formatted
	 */
	public String toString();
}