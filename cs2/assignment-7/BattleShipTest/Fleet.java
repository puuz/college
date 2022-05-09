package BattleShipTest;

public class Fleet implements FleetAPI {
	private final int fleetSize = 7;
	private Ship[] ships = new Ship[this.fleetSize];
	public void deployFleet() {
		for (int i = 0; i < this.fleetSize; i++) {
			Ship ship = new Ship();
			Location location = new Location();
			ship.setLocation(location);
			do {
				location.pick();
			} while (this.check(location, i) != -1);
			this.ships[i] = ship;
		}
	}
	public boolean operational() {
		for (int i = 0; i < this.fleetSize; i++) {
			if (!this.ships[i].isSunk()) return true;
		}
		return false;
	}
	public boolean isHitNSink(Location location) {
		for (int i = 0; i < this.fleetSize; i++) {
			Ship ship = this.ships[i];
			if (ship.getLocation().toString().equals(location.toString())) {
				ship.sink();
				return true;
			}
		}
		return false;
	}
	public void printFleet() {
		for (int i = 0; i < this.fleetSize; i++) {
			this.ships[i].printShip();
			if (this.fleetSize == i + 1) System.out.print("\n");
			else System.out.print(", ");
		}
	}
	public int check(Location location, int currentSize) {
		for (int i = 0; i < currentSize; i++) {
			if (this.ships[i].match(location)) return i;
		}
		return -1;
	}
}