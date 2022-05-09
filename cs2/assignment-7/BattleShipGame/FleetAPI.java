package BattleShipGame;

public interface FleetAPI {
	/**
	 * @brief deploys the ships in random locations of the ocean
	 */
	public void deployFleet();
	/**
	 * @brief checks all the ships statuses
	 * @return whether at least one ship in the fleet is not sunk
	 */
	public boolean operational();
	/**
	 * @brief checks all the ships locations and sinks if there is a match
	 * @param location The location object to check if match then sink
	 * @return whether the location object matched one of the deployed ships
	 */
	public boolean isHitNSink(Location location);
	/**
	 * @brief prints out locations and statuses of ships in fleet
	 */
	public void printFleet();
	/**
	 * @brief checks all the ships locations to see if it exists of the passed location parameter
	 * @param location The location object to check if exists in fleet
	 * @param currentSize The amount of ships to loop over since it's fixed size of fleetSize property
	 * @return the index of where the location is located in the ships property, otherwise -1 for not found
	 */
	public int check(Location location, int currentSize);
}