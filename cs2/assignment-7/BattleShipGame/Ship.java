package BattleShipGame;

public class Ship implements ShipAPI {
	private Location location;
	private boolean sunk;
	public Ship() {
		this.sunk = false;
	}
	public Location getLocation() {
		return this.location;
	}
	public boolean match(Location location) {
		return location.toString().equals(this.location.toString());
	}
	public boolean isSunk() {
		return sunk;
	}
	public void sink() {
		this.sunk = true;
	}
	public void setLocation(Location location) {
		this.location = location;
	}
	public void printShip() {
		String status = "up";
		if (this.sunk) status = "sunk";
		System.out.print(this.location.toString() + " " + status);
	}
}