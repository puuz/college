#ifndef ITEM_H_12_9_2021
#define ITEM_H_12_9_2021

#include <string>

/**
* @class Item
*
* @brief Stores the item's itemCode, name, and quickKey.
*
* Stores the item's itemCode, name, and quickKey. Setters
* are used in the constructor, getters have it's own
* functions, and includes method to update quick key.
*/
class Item {
private:
	/** the item code of the item */
	std::string itemCode;
	/** the name of the item */
	std::string name;
	/** the quick key of the item */
	char quickKey;
public:
	/**
	* @brief Only constructor for item.
	*
	* Only constructor for item that sets the item code,
	* name, and quick key otherwise if one isn't passed
	* accordinally each one has a default value.
	*
	* @param nItemCode The new item code for item object.
	* @param nName The new name code for item object.
	* @param nQuickKey The new quick key for item object.
	*
	* 3 Tests
	*
	* Code:
	* Item item1("item code 1", "name 1", 'A');
	* cout << item1.getItemCode() << "\n"
	*	<< item1.getName() << "\n"
	*	<< item1.getQuickKey();
	*
	* Result:
	* item code 1
	* name 1
	* A
	*
	* Code:
	* Item item1("", "", 'u');
	* cout << item1.getItemCode() << "\n"
	*	<< item1.getName() << "\n"
	*	<< item1.getQuickKey();
	*
	* Result:
	* JNK
	* Unknown
	*
	*
	* Code:
	* Item item1("039", "ok lol", 'F');
	* cout << item1.getItemCode() << "\n"
	*	<< item1.getName() << "\n"
	*	<< item1.getQuickKey();
	*
	* Result:
	* 039
	* ok lol
	* F
	*/
	Item(std::string nItemCode, std::string nName, char nQuickKey);
	/**
	* @brief Gets the item code of the item.
	*
	* Gets the item code of the item.
	*
	* @return itemCode The item code of the item.
	*/
	std::string getItemCode() const;
	/**
	* @brief Gets the name of the item.
	*
	* Gets the name of the item.
	*
	* @return name The name of the item.
	*/
	std::string getName() const;
	/**
	* @brief Gets the quick key of the item.
	*
	* Gets the quick key of the item.
	*
	* @return quickKey The quick key of the item.
	*/
	char getQuickKey() const;
	//create 3 tests
	//try characters that are in and not in the range
	//of valid characters
	/**
	* @brief Updates the quick key of the item to the passed value
	*
	* Updates the quick key of the item to the passed value. It
	* won't do anything if the passed value is not a valid quic key.
	* From A - Z or empty 0.
	*
	* @param nQuickKey The new quick key to update to for the item.
	*
	* 3 Tests
	*
	* Code:
	* Item item1("039", "ok lol", 'u');
	* cout << item1.getItemCode() << "\n"
	*	<< item1.getName() << "\n"
	*	<< item1.getQuickKey();
	* item1.updateQuickKey('K');
	* cout << "\n" << item1.getQuickKey();
	*
	* Result:
	* 039
	* ok lol
	*
	* K
	*
	* Code:
	* Item item1("039", "ok lol", 'Z');
	* cout << item1.getItemCode() << "\n"
		<< item1.getName() << "\n"
		<< item1.getQuickKey();
	* item1.updateQuickKey('a');
	* cout << "\n" << item1.getQuickKey();
	*
	* Result:
	* 039
	* ok lol
	* Z
	* Z
	*
	* Code:
	* Item item1("039", "ok lol", 'B');
	* cout << item1.getItemCode() << "\n"
		<< item1.getName() << "\n"
		<< item1.getQuickKey();
	* item1.updateQuickKey('L');
	* cout << "\n" << item1.getQuickKey();
	*
	* Result:
	* 039
	* ok lol
	* B
	* L
	*/
	void updateQuickKey(char nQuickKey);
};

#endif