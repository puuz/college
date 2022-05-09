package BattleShipGame;

public interface ShipAPI {
	/**
	 * @brief gets the location property for the ship
	 * @return location property
	 */
	public Location getLocation();
	/**
	 * @brief returns true if this location matches the ship's location
	 * @param location The location to match with location property
	 * @return whether the locations of yx match
	 */
	public boolean match(Location location);
	/**
	 * @brief checks to see if the ship is sunk
	 * @return whether the ship has sunk
	 */
	public boolean isSunk();
	/**
	 * @brief sets sunk property for the ship to true
	 */
	public void sink();
	/**
	 * @brief sets the location property of the ship to the pass parameter
	 * @param location The location to set to the location property of the ship
	 */
	public void setLocation(Location location);
	/**
	 * @brief prints location and status of the ship
	 */
	public void printShip();
}