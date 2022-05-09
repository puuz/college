#ifndef PERSONA_H_12_9_2021
#define PERSONA_H_12_9_2021

#include "Item.h"
#include <iostream>

/**
* @class Persona
*
* @brief Stores the persona's personaCode, id, and array of item pointers.
*
* Stores the persona's personaCode, id, and array of item pointers.
* Setters are used in the constructor, there's simple and unique getters
* with it's own functions, and includes methods to manipulate the private data.
*/
class Persona {
private:
	/** the persona code of the persona */
	std::string personaCode;
	/** the id of the persona */
	std::string id;
	/** the array of item pointers for the persona */
	Item* items[5];
public:
	//project 3
	/**
	* @brief Copy constructor for persona including items array.
	*
	* Copy constructor for persona include items array. It'll
	* either set the new item if the current is nullptr or
	* set it to nullptr if the current is nullptr.
	*
	* @param pers The persona object to copy over.
	*/
	Persona(const Persona & pers);
	/**
	* @brief The assignment operator for the persona class.
	*
	* The assignment operator for the persona class. It'll
	* make sure that all the current items in the assignment are
	* deleted from memory then do the same thing as the copy
	* constructor then returns a reference to that current object.
	*
	* @param p The persona object that it's assigned to.
	*/
	Persona & operator=(const Persona & p);
	/**
	* @brief The insertion operator for the persona class.
	*
	* The insertion operator for the persona class. It'll output
	* the persona object used on the insertation in correct format
	* one by one. First the persona's id and code then each items
	* array.
	*
	* @param out The output stream to use on the insertion.
	* @param p The persona object to prompt to the output stream.
	*/
	friend std::ostream & operator<<(std::ostream & out, const Persona & p);
	/**
	* @brief The extraction operator for the persona class.
	*
	* The extraction operator for the persona class. It'll first though
	* delete each item in the persona object from memory and set it to nullptr
	* then it'll start reading in the persona object's data. For the items
	* there will only be on new item object if all the read in data is a "-".
	*
	* @param in The input stream to use on the extraction.
	* @param p The persona object for deleting and reassigning.
	*/
	friend std::istream & operator>>(std::istream & in, Persona & p);
	/**
	* Testing
	* 
	* Code:
	* Persona p1("persona_code_1", "persona_id_1");
	* p1.addItem("item_code_1", "item_name_1", 'A');
	* p1.addItem("item_code_2", "item_name_2", '0'); it really had slash but webcat doesn't like it
	* p1.removeItem(0);
	* p1.addItem("item_code_3", "item_name_3", 'f');
	* p1.addItem("item_code_4", "item_name_4", 'Z');
	* cout << "Insertion: " << p1 << "\n";
	* Persona pCopy(p1);
	* cout << "Copy: " << pCopy << "\n";
	* stringstream cInput;
	* cInput << "first_402 NJF VMO second_490 j KVL bob_9450 N KFV for_583 C - - - HFJ last_023 U ";
	* Persona p2;
	* cInput >> p2;
	* cout << "Extraction: " << p2 << "\n";
	* p1 = p2;
	* cout << "Assignment: " << p1 << "\n";
	* 
	* Result:
	* Insertion: persona_id_1 persona_code_1 item_code_3 item_name_3  item_code_2 item_name_2  item_code_4 item_name_4 Z - - - - - -
	* Copy: persona_id_1 persona_code_1 item_code_3 item_name_3  item_code_2 item_name_2  item_code_4 item_name_4 Z - - - - - -
	* Extraction: first_402 NJF VMO second_490  KVL bob_9450 N KFV for_583 C - - - HFJ last_023 U
	* Assignment: first_402 NJF VMO second_490  KVL bob_9450 N KFV for_583 C - - - HFJ last_023 U
	* 
	* Code:
	* Persona p1("persona_code_1", "persona_id_1");
	* p1.addItem("item_code_1", "item_name_1", 'A');
	* p1.addItem("item_code_2", "item_name_2", '0'); it really had slash but webcat doesn't like it
	* p1.addItem("item_code_3", "item_name_3", 'f');
	* p1.addItem("item_code_4", "item_name_4", 'Z');
	* p1.removeItem(3);
	* cout << "Insertion: " << p1 << "\n";
	* Persona pCopy(p1);
	* cout << "Copy: " << pCopy << "\n";
	* stringstream cInput;
	* cInput << "cause_94 IVK E - - - - - - NKD um_940 A JVM it_904 C JNV fast_490 U - - - ";
	* Persona p2;
	* cInput >> p2;
	* cout << "Extraction: " << p2 << "\n";
	* p1 = p2;
	* cout << "Assignment: " << p1 << "\n";
	* 
	* Result:
	* Insertion: persona_id_1 persona_code_1 item_code_1 item_name_1 A item_code_2 item_name_2  item_code_3 item_name_3  - - - - - -
	* Copy: persona_id_1 persona_code_1 item_code_1 item_name_1 A item_code_2 item_name_2  item_code_3 item_name_3  - - - - - -
	* Extraction: cause_94 IVK E -  - - - - NKD  m_940 A J VM it_904 C
	* Assignment: cause_94 IVK E -  - - - - NKD  m_940 A J VM it_904 C
	*/
	//lab 9
	/**
	* @brief Default constructor for persona.
	*
	* Default constructor for persona that sets the persona code
	* to NPC, id to unknown_0, and each item pointer in the items array
	* to nullptr.
	*/
	Persona();
	/**
	* @brief Setter constructor for persona.
	*
	* Setter constructor for persona that sets the persona code to
	* the passed new persona code, id to the passed new id, and each
	* item pointer in the items array to nullptr.
	*
	* @param nPersonaCode The persona code of the persona.
	* @param nId The new id of the persona.
	*/
	Persona(std::string nPersonaCode, std::string nId);
	/**
	* @brief Only deconstructor for persona.
	*
	* Only deconstructor for persona and deletes every item pointer in the
	* items array from memory.
	*/
	~Persona();
	/**
	* @brief Gets the persona code of the persona.
	*
	* Gets the persona code of the persona.
	*
	* @return personaCode The persona code of the persona.
	*/
	std::string getPersonaCode() const;
	/**
	* @brief Gets the id of the persona.
	*
	* Gets the id of the persona.
	*
	* @return id The id of the persona.
	*/
	std::string getId() const;
	/**
	* @brief Gets the item object for the passed position.
	*
	* Gets the item pointer for the item object of the passed position.
	* The returned item pointer can't be changed what it points to. It'll
	* also return a nullptr if the passed position is not valid for array.
	*
	* @param posOfItem The position of the item to get in the item pointer array.
	*
	* @return item object/nullptr The item object of the passed position or
	* nullptr if not valid passed position.
	*/
	const Item* getItem(int posOfItem) const;
	/**
	* @brief Adds a new item object with the passed data to the array of item pointers.
	*
	* Adds a new item object with the passed data to the array of item pointers. It'll
	* only add the new item object if the array contains a nullptr meaning it's not full yet.
	*
	* @param nItemCode The new item code in the new item object getting added.
	* @param nName The new name in the new item object getting added.
	* @param nQuickKey The new quick key in the new item object getting added.
	*
	* @return true/false The state on whether the item was added or not.
	*/
	bool addItem(std::string nItemCode, std::string nName, char nQuickKey);
	/**
	* @brief Removes an item object at the passed position in the array.
	*
	* Removes an item object at the passed position in the array. It'll only remove
	* the item object if the passed position is valid for the array and the position
	* is not already a nullptr. Removing will delete the item pointer from memory and
	* also set it to nullptr.
	*
	* @param posOfItem The position in the array of the item object to remove.
	*
	* @return true/false The state on whether the item was removed or not.
	*/
	bool removeItem(int posOfItem);
	/**
	* @brief Gets the number of item pointers in the items array that isn't nullptr.
	*
	* Gets the number of item pointers in the items array that isn't nullptr. By looping
	* through the array and checking if each is a nullptr.
	*
	* @return count The number of item pointers in the items array that isn't nullptr.
	*/
	int countItems() const;
	/**
	* @brief Finds the position the item pointer is in the array.
	*
	* Finds the position the item pointer is in the array. By passing the corresponding
	* quick key it has. It'll only return a valid position if the quick key is valid and
	* exists in at least one item object.
	*
	* @param findQuickKey The quick key the item object has that needs to found.
	*
	* @return posOfItem The position the item pointer is in the array or -1 if it wasn't found.
	*/
	int findByKey(char findQuickKey) const;
	/**
	* @brief Updates the found item object with the passed new quick key.
	*
	* Updates the found item object by the passed old quick key with the passed new quick key.
	* It'll only update if the quick key is valid and exists in at least one item object.
	*
	* @param oldQuickKey The old quick key the item object has the needs to be updated.
	* @param newQuickKey Thew new quick key the item object needs to be updated to.
	*/
	void updateKey(char oldQuickKey, char newQuickKey);
	/**
	* Testing
	*
	* default constructor - 1
	* setter constructor - 2
	* addItem - 6+
	* removeItem - 3
	* countItems - 3
	* findByKey - 3
	* updateKey - 3
	* getItem - 3
	*
	* Code:
	* Persona persona1;
	* cout << persona1.getPersonaCode() << "\n"
		<< persona1.getId() << "\n";
	* persona1.addItem("Item Code 1", "Name 1", 'U');
	* persona1.updateKey('U', 'K');
	* cout << persona1.getItem(persona1.findByKey('K'))->getName() << "\n";
	* persona1.addItem("Item Code 2", "Name 2", 'n');
	* cout << persona1.removeItem(10) << "\n";
	* persona1.addItem("Item Code 3", "Name 2", 'Z');
	* cout << persona1.countItems();
	*
	* Result:
	* NPC
	* unknown_0
	* Name 1
	* 0
	* 3
	*
	* Code:
	* Persona persona1("persona code 1", "id 1");
	* cout << persona1.getPersonaCode() << "\n"
		<< persona1.getId() << "\n";
	* persona1.addItem("Item Code 1", "Name 1", 'U');
	* persona1.removeItem(0);
	* cout << persona1.countItems() << "\n";
	* cout << persona1.getItem(persona1.findByKey('U'))->getItemCode();
	* persona1.addItem("Item Code 2", "Name 2", 'n');
	* persona1.updateKey('n', '*');
	* persona1.addItem("Item Code 3", "Name 2", 'Z');
	*
	* Result:
	* persona code 1
	* id 1
	* 0
	*
	*
	* Code:
	* Persona persona1("", "id 1");
	* cout << persona1.getPersonaCode() << "\n"
		<< persona1.getId() << "\n";
	* persona1.addItem("Item Code 1", "Name 1", 'o');
	* persona1.updateKey('o', 'N');
	* persona1.addItem("Item Code 2", "Name 2", 'O');
	* cout << persona1.getItem(persona1.findByKey('O'))->getQuickKey() << "\n";
	* cout << persona1.removeItem(0) << "\n";
	* persona1.addItem("Item Code 3", "Name 2", 'A');
	* cout << persona1.countItems();
	*
	* Result:
	*
	* id 1
	* O
	* 1
	* 2
	*/
};

#endif
