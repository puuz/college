/**
 * @file SiteRank.cpp
 *
 * @brief Converts the number of points earned on awesomeCode.com to a rank.
 *
 * The program converts the number of points earned on awesomeCode.com
 * to a rank. The rank is based on the following table:
 *
 * Points	Rank
 * < 1		Invalid
 * 1		Newbie
 * 2-9		Novice
 * 10-49	Professional
 * 50-249	Expert
 * 250+		Guru
 *
 * All members of the site start with 1 point.
 *
 * @date 03-Oct-2017
 * @author turners
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Converts the number of points earned on awesomeCode.com to a rank.
 *
 * The program converts the number of points earned on awesomeCode.com
 * to a rank. The rank is based on the following table:
 *
 * Points	Rank
 * < 1		Invalid
 * 1		Newbie
 * 2-9		Novice
 * 10-49	Professional
 * 50-249	Expert
 * 250+		Guru
 *
 * All members of the site start with 1 point.
 *
 * @return 0 on success and non-0 on error
 *
 * TESTS:
 * 
 * Enter your experience score: -10
 * With an experience score of -10 you have a rank of Invalid.
 * 
 * Enter your experience score: 7
 * With an experience score of 7 you have a rank of Novice.
 * 
 * Enter your experience score: 1840280
 * With an experience score of 1840280 you have a rank of Guru.
 * 
 * Enter your experience score: 54
 * With an experience score of 54 you have a rank of Expert.
 * 
 * Enter your experience score: 22
 * With an experience score of 22 you have a rank of Professional.
 * 
 * Enter your experience score: 1
 * With an experience score of 1 you have a rank of Newbie.
 */

int main() {
	int score;

	cout << "Enter your experience score: ";
	cin >> score;

	string rank;

	if (score < 1) {
		rank = "Invalid";
	} else if (score == 1) {
		rank = "Newbie";
	} else if (score >= 2 && score <= 9) {
		rank = "Novice";
	} else if (score >= 10 && score <= 49) {
		rank = "Professional";
	} else if (score >= 50 && score <= 249) {
		rank = "Expert";
	} else {
		rank = "Guru";
	}

	cout << "\n\nWith an experience score of " << score
		<< " you have a rank of " << rank << ".\n\n";

	return 0;
}