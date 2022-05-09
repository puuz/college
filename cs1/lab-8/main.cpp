/**
* @file main.cpp
*
* @brief Adds, removes, gets orders and prompts them with format.
* 
* Adds items to the order, removes items from the order, and gets items from
* an order. It'll also prompt with formatting the entire order with ids, dates,
* and names of each item in the order.
*
* @author Sam Farris
* @date 12/6/2021
*/

#include "lab8.h"

//doxygen comments and tests are in lab8.h file
//had to include friend operator doxygen comments here too because of webcat

/** max items in the array */
const int MAX_ITEMS = 10;

//item class
Item::Item() {
	id = -1;
	name = "";
	date = "";
}
Item::Item(int nId, std::string nDate, std::string nName) {
	id = nId;
	date = nDate;
	name = nName;
}
int Item::getItemId() const {
	return id;
}
std::string Item::getDate() const {
	return date;
}
std::string Item::getName() const {
	return name;
}
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
std::ostream & operator << (std::ostream & output, const Item & item) {
	//prompt and format item data
	output << std::right << std::setw(8) << item.getItemId() << " "
		<< std::left << std::setw(10) << item.getDate() << " "
		<< std::left << item.getName();
	return output;
}

//order class
Order::Order() {
	numOfItems = 0;
}
int Order::getCount() const {
	return numOfItems;
}
Item Order::getItem(int position) const {
	//check if position is valid for items array
	if (position >= 0 && position < numOfItems) {
		//return item object in array at passed position
		return items[position];
	}
	else {
		//return default constructor
		return Item();
	}
}
bool Order::addItem(int nId, std::string nDate, std::string nName) {
	//numOfItems and MAX_ITEMS is counted one more than current position
	//returns false if items array is full
	if (numOfItems == MAX_ITEMS) {
		return false;
	}
	else {
		//numOfItems++ adds after declaration
		//returns true and assigns new items object to next position in items array
		items[numOfItems++] = Item(nId, nDate, nName);
		return true;
	}
}
int Order::findItem(int findId) const {
	for (int i = 0; i < numOfItems; i++) {
		//once passed id is equal to the item's id return position 
		if (findId == items[i].getItemId()) {
			return i;
		}
	}
	//if passed id was never found return -1
	return -1;
}
bool Order::removeItem(int removeId) {
	//assign position in array of passed id for item
	int i = findItem(removeId);
	//if item was found start loop to remove it otherwise return false
	if (i != -1) {
		//start loop at position found for passed id and stop one less than number of items
		for (i; i < numOfItems - 1; i++) {
			//for each item assign the current with the next
			items[i] = items[i + 1];
		}
		//update the number of items so duplicate at end is ignored
		numOfItems--;
		return true;
	}
	else {
		return false;
	}
}
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
std::ostream & operator << (std::ostream & output, const Order & order) {
	//loop the number of items in the array
	for (int i = 0; i < order.getCount(); i++) {
		//assign item object with gotten item in array from position in loop
		Item item = order.getItem(i);
		//prompt position in array and item output operator with new line feeds each time
		output << std::right << std::setw(5) << i << item << std::endl;
	}
	return output;
}