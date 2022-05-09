package BattleShipGame;

import java.util.Scanner;

public class Game {
	public static void main(String args[]) {
		Fleet fleet = new Fleet();
		fleet.deployFleet();
		Location location = new Location();
		Scanner stdin = new Scanner(System.in);
		String guess;
		do {
			location.fire();
			guess = stdin.nextLine();
			if (!location.setLocation(guess)) {
				System.out.println("The coordinates weren't formatted correctly");
				continue;
			}
			if (!fleet.isHitNSink(location)) {
				System.out.println("Missed at location " + location.toString());
				continue;
			}
			System.out.println("Hit at location " + location.toString());
		} while(fleet.operational());
		System.out.println("You win, all ships have sunk!");
		stdin.close();
	}
}