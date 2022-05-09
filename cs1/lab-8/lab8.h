#ifndef LAB8_H_12_6_2021
#define LAB8_H_12_6_2021

#include <string>
#include <iomanip>
#include <iostream>

/**
* @class Item
* 
* @brief Stores the item's id, date, and name.
* 
* Stores the item's id, date, and name. Setters
* are used in the constructor, getters have it's
* own functions, and includes friend output
* operator.
* 
* 3 Tests (Operator is tested in order tests techniqually)
* 
* Code:
* Item item1;
* std::cout << item1.getItemId() << std::endl
*	<< item1.getDate() << std::endl
*	<< item1.getName() << std::endl;
* 
* Result:
* -1
* 
* 
* 
* Code:
* Item item1(234, "12/6/2021", "Super Cool");
* std::cout << item1.getItemId() << std::endl
*	<< item1.getDate() << std::endl
*	<< item1.getName() << std::endl;
* 
* Result:
* 234
* 12/16/2021
* Super Cool
* 
* Code:
* Item item1(-10, "", "Not Good");
* std::cout << item1.getItemId() << std::endl
*	<< item1.getDate() << std::endl
*	<< item1.getName() << std::endl;
* 
* Result:
* -10
* 
* Not Good
*/
class Item {
private:
	/** the id of the item */
	int id;
	/** the date of the item */
	std::string date;
	/** the name of the item */
	std::string name;
public:
	/**
	* @brief Default constructor for item.
	* 
	* Default constructor for item that sets the
	* id to -1 and the date and name to an empty
	* string.
	*/
	Item();
	/**
	* @brief Setter constructor for item.
	* 
	* Setter constructor for item that sets the
	* id, date, and name to the passed id, date,
	* and name.
	* 
	* @param nId The new id of the item.
	* @param nDate The new date of the item.
	* @param nName The new name of the item.
	*/
	Item(int nId, std::string nDate, std::string nName);
	/**
	* @brief Gets the id of the item.
	* 
	* Gets the id of the item.
	*/
	int getItemId() const;
	/**
	* @brief Gets the date of the item.
	* 
	* Gets the date of the item.
	*/
	std::string getDate() const;
	/**
	* @brief Gets the name of the item.
	*
	* Gets the name of the item.
	*/
	std::string getName() const;
	/**
	* @brief Prompts and formats the item's data.
	* 
	* Prompts and formats the item's data with
	* spaces between each item data.
	* 
	* @param output The output stream to prompt data to.
	* @param item The item object to get item data from.
	* 
	* @return output The output stream to prompt data to.
	*/
	friend std::ostream & operator<<(std::ostream & output, const Item & item);
};

/**
* @class Order
*
* @brief Stores the order's items and number of items.
*
* Stores the order's items as an array and number of
* items in that array. There's also functions to interact
* with the array like getting, adding, finding, and removing.
* Along with a friend output operator to prompt position and
* includes the input operator.
*
* 3 Tests
*
* Code:
* Order order1;
* order1.addItem(930, "12/11/2021", "Cheese");
* order1.addItem(051, "12/8/2015", "Chips");
* std::cout << order1.findItem(930) << std::endl;
* order1.addItem(40, "4/2/2017", "Apples");
* order1.removeItem(40);
* order1.addItem(3023, "12/8/2017", "Ketchup");
* std::cout << order1.getItem(2) << std::endl;
* order1.addItem(2032, "12/9/2017", "French Fries");
* std::cout << order1;
*
* Result:
* 0
*   3023 12/8/2017  Ketchup
*   0     930 12/11/2021 Cheese
*   1      41 12/8/2015  Chips
*   2    3023 12/8/2017  Ketchup
*   3    2032 12/9/2017  French Fries
*
* Code:
* Order order1;
* order1.addItem(930, "12/11/2021", "Cheese");
* order1.removeItem(930);
* std::cout << order1.getItem(0) << std::endl;
* order1.addItem(051, "12/8/2015", "Chips");
* order1.addItem(40, "4/2/2017", "Apples");
* std::cout << order1.findItem(930) << std::endl;
* order1.addItem(3023, "12/8/2017", "Ketchup");
* order1.addItem(2032, "12/9/2017", "French Fries");
* std::cout << order1;
*
* Result:
*        -1
* -1
*	 0      41 12/8/2015  Chips
*    1      40 4/2/2017   Apples
*    2    3023 12/8/2017  Ketchup
*    3    2032 12/9/2017  French Fries
*
* Code:
* Order order1;
* order1.addItem(930, "12/11/2021", "Cheese");
* order1.removeItem(0);
* std::cout << order1.getItem(50) << std::endl;
* order1.addItem(051, "12/8/2015", "Chips");
* order1.addItem(40, "4/2/2017", "Apples");
* std::cout << order1.findItem(-10) << std::endl;
* order1.addItem(3023, "12/8/2017", "Ketchup");
* order1.addItem(2032, "12/9/2017", "French Fries");
* order1.addItem(3023, "12/8/2017", "Ketchup");
* order1.addItem(2032, "12/9/2017", "French Fries");
* order1.addItem(051, "12/8/2015", "Chips");
* order1.addItem(930, "12/11/2021", "Cheese");
* order1.addItem(930, "12/11/2021", "Cheese");
* order1.addItem(051, "12/8/2015", "Chips");
* order1.addItem(2032, "12/9/2017", "French Fries");
* std::cout << order1;
*
* Result:
*        -1
* -1
*    0     930 12/11/2021 Cheese
*    1      41 12/8/2015  Chips
*    2      40 4/2/2017   Apples
*    3    3023 12/8/2017  Ketchup
*    4    2032 12/9/2017  French Fries
*    5    3023 12/8/2017  Ketchup
*    6    2032 12/9/2017  French Fries
*    7      41 12/8/2015  Chips
*    8     930 12/11/2021 Cheese
*    9     930 12/11/2021 Cheese
*/
class Order {
private:
	/** array of items holding each object */
	Item items[10];
	/** number of items in the array */
	int numOfItems;
public:
	/**
	* @brief Default constructor for item.
	*
	* Default constructor for item that sets the
	* number of items to 0.
	*/
	Order();
	/**
	* @brief Gets the count of number of items in array.
	* 
	* Gets the count of number of items in array.
	* 
	* @returns numOfItems The number of items in array.
	*/
	int getCount() const;
	/**
	* @brief Gets the item for the passed position in array.
	* 
	* Gets the item object for the passed position in array. Will
	* return the default item if position is not valid for the array.
	* 
	* @param position The position of the item in the array to get.
	* 
	* @return item The item object for the passed position in array.
	*/
	Item getItem(int position) const;
	/**
	* @brief Adds a new item object to the array with the passed data.
	* 
	* Adds a new item object to the array with the passed data. Will
	* return false and add nothing if the array is full.
	* 
	* @param nId The new id in the new item getting added to the array.
	* @param nDate The new date in the new item getting added to the array.
	* @param nName The new name in the new item getting added to the array.
	* 
	* @return true/false Whether if the item was added to the array.
	*/
	bool addItem(int nId, std::string nDate, std::string nName);
	/**
	* @brief Finds the item's position for the passed id.
	* 
	* Finds the item's position in the items array for the passed id.
	* Will return -1 position if no items in the array have the passed id.
	* 
	* @param  findId The item's id of the position to get.
	* 
	* @return i The position of the item in the items array.
	*/
	int findItem(int findId) const;
	/**
	* @brief Removes the item object for the passed id.
	* 
	* Removes the item object from the array items for the passed id.
	* Will return false if no items in the array have the passed id.
	* 
	* @param removeId The item's id of the item to remove.
	* 
	* @return true/false Whether if the item was removed from the array.
	*/
	bool removeItem(int removeId);
	/**
	* @brief Prompts and formats each item's data from order object.
	*
	* Prompts and formats each item's data and position in the item array
	* from the order object. With a line feed for each item.
	*
	* @param output The output stream to prompt data to.
	* @param order The order object to get order data from and manipulate.
	*
	* @return output The output stream to prompt data to.
	*/
	friend std::ostream & operator<<(std::ostream & output, const Order & order);
};

#endif