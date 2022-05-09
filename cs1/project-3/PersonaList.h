#ifndef PERSONALIST_H_12_12_2021
#define PERSONALIST_H_12_12_2021

#include "Persona.h"

/**
* @class PersonaList
*
* @brief Stores the persona list size, count, and array of personas.
*
* Stores the persona list size, count, and array of personas.
* Setters are used in the constructor, and has unique and specific
* methods to manipulate different things in the private data.
*/
class PersonaList {
private:
	/** the array of personas and it's dynamic */
	Persona * personas;
	/** the size of the array of personas, this can change when grown */
	int size;
	/** the number of personas in the personas array */
	int count;
	/**
	* @brief Grows the personas array by doubling the size.
	*
	* Grows the personas array by doubling the size. The process is creating
	* a new array of that doubled size which is the array that will replace the
	* previous. Reassing each persona so to move everything over. Finally delete
	* the old personas array from memory.
	*/
	void growArray();
public:
	/**
	* @brief The default constructor for the persona list.
	*
	* The default constructor for the persona list. With personas
	* array starting at a size of 5 and count at 0 at default.
	*/
	PersonaList();
	/**
	* @brief Only deconstructor for persona list.
	*
	* Only deconstructor for persona list and deletes the personas array
	* from memory.
	*/
	~PersonaList();
	/**
	* @brief Gets the count of the personas array.
	*
	* Gets the count of the personas array
	*
	* @return count The count of the personas array.
	*/
	int getPersonaCount() const;
	/**
	* @brief Gets the persona object at the passed position.
	*
	* Gets the persona object at the passed position. This will return nullptr
	* if the passed position is not inbetween 0 and the count.
	*
	* @param posOfPersona The position of the persona to get from the personas array.
	*
	* @return persona object/nullptr The persona object of the passed position or nullptr
	* if not valid passed position.
	*/
	Persona * getPersona(int posOfPersona);
	/**
	* @brief Gets the persona object at the passed position.
	*
	* Gets the persona object at the passed position. This will return nullptr
	* if the passed position is not inbetween 0 and the count. This is the same
	* function above except this returns a const Persona which cannot be changed.
	*
	* @param posOfPersona The position of the persona to get from the personas array.
	*
	* @return persona object/nullptr The persona object of the passed position or nullptr
	* if not valid passed position.
	*/
	const Persona * getPersona(int posOfPersona) const;
	/**
	* @brief Adds the passed persona object to the personas array.
	*
	* Adds the passed persona object to the personas array. If the current count and size
	* is the same it'll dynamically grow the array 2 times larger than it previously was.
	*
	* @param p The persona object to add to the personas array.
	*/
	void addPersona(Persona p);
	/**
	* @brief Finds the persona object by the passed persona id.
	*
	* Finds the persona object by the passed persona id. If the id cannot be found
	* it'll return nullptr.
	*
	* @param findId The id of the persona to find in the personas array.
	*
	* @return persona object/nullptr The persona object of the passed persona id or nullptr
	* if the id doesn't exist in any personas.
	*/
	Persona * findPersona(std::string findId);
	/**
	* @brief Resets all of the quick keys that have the passed quick key.
	*
	* Resets all of the quick keys that have the passed quick key. Every time a quick key
	* is found in the personas it resets then adds on to the current count of changed personas.
	*
	* @param resetQuickKey The quick key to reset in all personas.
	*
	* @return changed The number of persona lists that were changed.
	*/
	int resetKeyBindings(char resetQuickKey);
	/**
	* @brief Resets the entire persona list by just setting count to 0.
	*
	* Resets the entire persona list by just setting count to 0.
	*/
	void resetList();
	/**
	* Code:
	* Persona tempP;
	* PersonaList personas;
	* stringstream listInput;
	* listInput << "bear_2633 MON SWP sword_9984 I SCR crown_9986 K WPN sword_9985 G - - - SWP metal_9987 U \n"
	*	<< "rat_2634 ENE - - - PTN fish_9989 G - - - JNK shield_9988 W - - - \n"
	*	<< "scarecrow_2635 MON CFT bow_9990 F PTN space_hamster_9993 J PTN diamond_9992 W GEM metal_9994 L JNK potion_of_strength_9991 U \n"
	*	<< "mage_2636 MON - - - QUE crown_9995 E QUE shield_9996 O - - - - - - \n"
	*	<< "rat_2637 ANI SWP shield_9999 F JNK armor_9998 K - - - CFT broken_sword_9997 T JNK arrow_10000 D \n"
	*	<< "rat_2638 PLA BOW knife_10002 W - - - SWP arrow_10001 L SCR helmet_10003 M GEM crown_10004 D \n"
	*	<< "bear_2641 PLA CON arrow_10226 Q - - - - - - GEM diamond_10227 O SCR knife_10228 R \n"
	*	<< "villager_2639 SPC SWP wand_10007 F - - - QUE broken_shield_10006 V - - - PTN space_hamster_10005 V \n"
	*	<< "warrior_2640 BKG CON potion_of_strength_10011 R CON diamond_10009 B SWP potion_of_speed_10008 S CON ruby_10012 R PTN gold_10010 M \n"
	*	<< "villager_2641 BKG QUE broken_armor_10013 Y WPN metal_10016 W SCR potion_of_speed_10017 D SWP knife_10014 L QUE wood_10015 V \n"
	*	<< "thief_2642 BKG - - - CFT wood_10019 E BOW shoe_10020 X GEM potion_of_strength_10018 Q - - - \n";
	* listInput >> tempP;
	* while (listInput) {
	*	personas.addPersona(tempP);
	*	listInput >> tempP;
	* }
	* cout << "\nAdd Persona: \n";
	* for (int i = 0; i < 11; i++) {
	*	cout << personas.getPersona(i)->getId() << "\n";
	* }
	* cout << "No Persona (0): ";
	* cout << personas.getPersona(11) << "\n";
	* cout << "\n\nFinds:";
	* cout << "\nvillager_2639: ";
	* personas.resetKeyBindings('F');
	* cout << *personas.findPersona("villager_2639");
	* cout << "\nNot found: " << personas.findPersona("cheese_01");
	* personas.resetList();
	* cout << "\nFinds After Reset: "
	*	<< *personas.findPersona("villager_2639");
	* 
	* Result:
	* Add Persona:
	* bear_2633
	* rat_2634
	* scarecrow_2635
	* mage_2636
	* rat_2637
	* rat_2638
	* bear_2641
	* villager_2639
	* warrior_2640
	* villager_2641
	* thief_2642
	* No Persona (0): 00000000
	*
	*
	* Finds:
	* villager_2639: villager_2639 SPC SWP wand_10007  - - - QUE broken_shield_10006 V - - - PTN space_hamster_10005 V
	* Not found: 00000000
	* Finds After Reset:
	*/
};

#endif