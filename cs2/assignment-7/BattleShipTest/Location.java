package BattleShipTest;

import java.util.Random;

public class Location implements LocationAPI {
	private final int fieldSize = 7;
	private int x;
	private char y;
	public Location() {
		this.x = -1;
		this.y = '*';
	}
	/**
	 * @param location The yx inputed from the user
	 * @return whether the location is in correct format
	 */
	private boolean isLocation(String location) {
		int x = (int) location.charAt(1) - '0';
		int y = (int) location.charAt(0) - 'a';
		return !(location.length() != 2 || x < 1 || x > 7 || y < 0 || y > 6);
	}
	public boolean setLocation(String location) {
		if (isLocation(location)) {
			this.x = Character.getNumericValue(location.charAt(1));
			this.y = location.charAt(0);
			return true;
		}
		return false;
	}
	public void pick() {
		Random random = new Random();
		this.x = random.nextInt(this.fieldSize) + 1;
		this.y = (char) (random.nextInt(this.fieldSize) + 'a');
	}
	public void fire() {
		System.out.println("Please input coordinates (<a-g><1-7>, ie: c3) for the next shot:");
	}
	public void print() {
		System.out.println(this.toString());
	}
	public String toString() {
		return this.y + "" + this.x;
	}
}