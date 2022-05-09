#ifndef PERSONAUTIL_H_12_12_2021
#define PERSONAUTIL_H_12_12_2021

#include <sstream>
#include "PersonaList.h"

/**
* @class PersonaUtil
*
* @brief Stores the persona util list. With useful manipulating functions.
*
* Stores the persona util list. With private functions to manipulate
* the load personas process effectively and same other public functions
* like getting, saving the data, and clearing it.
*/
class PersonaUtil {
private:
	/** persona list pointer */
	PersonaList * list;
	/**
	* @brief To handle persona commands.
	*
	* To handle persona commands. It'll read in a persona then add the persona
	* from what was read in. To the persona list.
	* 
	* @param in The input stream of the persona command.
	*/
	void personaCommand(std::istream & in);
	/**
	* @brief To handle add item commands.
	*
	* To handle add item commands. It'll add the item to the persona id that was inputted
	* through the input stream but it won't do anything if the persona id was incorrect.
	* Also meaning the persona is nullptr.
	* 
	* @param in The input stream of the add item command.
	*/
	void addItemCommand(std::istream & in);
	/**
	* @brief To handle remove item commands.
	*
	* To handle remove item commands. It'll remove the item to the persona id that was inputted
	* for the item position that was also inputted but it won't do anything persona id was incorrect
	* or if the item slot didn't exist.
	* 
	* @param in The input stream of the remove item command.
	*/
	void removeItemCommand(std::istream & in);
public:
	/**
	* @brief Only construstor for the persona util.
	*
	* Only constructor for the persona util that assigns the list
	* to the passed persona list in the constructor.
	*
	* @param nList The new persona list to take commands from.
	*/
	PersonaUtil(PersonaList * nList);
	/**
	* @brief Gets the list of the persona util.
	*
	* Gets the list of the persona util.
	*
	* @return list The list of this object that is being manipulated through the commands.
	*/
	PersonaList * getPersonas();
	/**
	* @brief Loads personas into the list by receiving commands over and over the input stream fails.
	*
	* Loads personas into the list by receiving commands over and over the input stream fails.
	* The only commands that are accepted are persona to make a persona and add it to the list, add item
	* to add an item to an existing persona and remove item to remove an item from an existing persona.
	*
	* @param in The input stream to read in the commands.
	*/
	void loadPersonas(std::istream & in);
	/**
	* @brief Saves the read in data from the list and returns it as a formatted string.
	*
	* Saves the read in data from the list and returns it as a formatted string. It'll
	* return an emptry string if list is currently nullptr.
	*
	* @return list The list dereferenced if the it has data to save or an emptry string if nullptr.
	*/
	std::string savePersonas();
	/**
	* @brief Clears each key in the quick keys array for each persona.
	*
	* Clears each key in the quick keys array for each persona. It isn't
	* required to have the key be anymore as if it isn't it'll prompt to the
	* result saying none was changed.
	*
	* @param quickKeys The array of quick keys to clear.
	* @param keysSize The size of the quick keys arary.
	*
	* @return changed The cleared keys and how many it cleared for each one.
	*/
	std::string clearKeys(char quickKeys[], int keysSize);
	/**
	* Code:
	* PersonaList eList;
	* PersonaUtil util(&eList);
	* stringstream test1;
	* test1 << "persona bear_2633 MON SWP sword_9984 I SCR crown_9986 K WPN sword_9985 G - - - SWP metal_9987 T \n"
	*	"persona rat_2634 ENE - - - PTN fish_9989 G - - - JNK shield_9988 W - - - \n"
	*	"persona scarecrow_2635 MON CFT bow_9990 F PTN space_hamster_9993 J PTN diamond_9992 W GEM metal_9994 L JNK potion_of_strength_9991 U \n"
	*	"persona mage_2636 MON - - - QUE crown_9995 E QUE shield_9996 O - - - - - - \n"
	*	"persona rat_2637 ANI SWP shield_9999 F JNK armor_9998 K - - - CFT broken_sword_9997 T JNK arrow_10000 D \n"
	*	"persona rat_2638 PLA BOW knife_10002 W - - - SWP arrow_10001 L SCR helmet_10003 M GEM crown_10004 D \n"
	*	"persona villager_2639 SPC SWP wand_10007 T - - - QUE broken_shield_10006 V - - - PTN space_hamster_10005 V \n"
	*	"persona bear_2641 PLA CON arrow_10226 Q - - - - - - GEM diamond_10227 T SCR knife_10228 R \n"
	*	"persona warrior_2640 BKG CON potion_of_strength_10011 R CON diamond_10009 B SWP potion_of_speed_10008 S CON ruby_10012 T PTN gold_10010 M \n"
	*	"persona villager_2641 BKG QUE broken_armor_10013 Y WPN metal_10016 W SCR potion_of_speed_10017 D SWP knife_10014 L QUE wood_10015 V \n";
	* util.loadPersonas(test1);
	* cout << util.getPersonas()->getPersonaCount();
	* cout << "\n\nSave Persona:\n\n" << util.savePersonas();
	* char keys[4] = { 'G', 'Y', 'Z', 'T' };
	* cout << "\n\nClear Keys:\n\n" << util.clearKeys(keys, 4);
	*
	* Result:
	* 10
	*
	* Save Persona:
	* persona bear_2633 MON SWP sword_9984 I SCR crown_9986 K WPN sword_9985 G - - - SWP metal_9987 T
	* persona rat_2634 ENE - - - PTN fish_9989 G - - - JNK shield_9988 W - - -
	* persona scarecrow_2635 MON CFT bow_9990 F PTN space_hamster_9993 J PTN diamond_9992 W GEM metal_9994 L JNK potion_of_strength_9991 U
	* persona mage_2636 MON - - - QUE crown_9995 E QUE shield_9996 O - - - - - -
	* persona rat_2637 ANI SWP shield_9999 F JNK armor_9998 K - - - CFT broken_sword_9997 T JNK arrow_10000 D
	* persona rat_2638 PLA BOW knife_10002 W - - - SWP arrow_10001 L SCR helmet_10003 M GEM crown_10004 D
	* persona villager_2639 SPC SWP wand_10007 T - - - QUE broken_shield_10006 V - - - PTN space_hamster_10005 V
	* persona bear_2641 PLA CON arrow_10226 Q - - - - - - GEM diamond_10227 T SCR knife_10228 R
	* persona warrior_2640 BKG CON potion_of_strength_10011 R CON diamond_10009 B SWP potion_of_speed_10008 S CON ruby_10012 T PTN gold_10010 M
	* persona villager_2641 BKG QUE broken_armor_10013 Y WPN metal_10016 W SCR potion_of_speed_10017 D SWP knife_10014 L QUE wood_10015 V
	*
	* Clear Keys:
	*
	* Keys Cleared
	* G       2
	* Y       1
	* Z       None
	* T       5
	*/
};

#endif
