/**
* @file Persona.cpp
*
* @brief The persona's constructors and functions
*
* The persona's constructors and functions to add,
* remove, get, and manipulate the private data.
*
* @author Sam Farris
* @date 12/9/2021
*/

#include "Persona.h"

/** max number of item pointers in the array */
const int MAX_ITEMS = 5;

Persona::Persona() {
	personaCode = "NPC";
	id = "unknown_0";
	//set each item pointer to nullptr
	for (int i = 0; i < MAX_ITEMS; i++) {
		items[i] = nullptr;
	}
}
Persona::Persona(std::string nPersonaCode, std::string nId) {
	personaCode = nPersonaCode;
	id = nId;
	//set each item pointer to nullptr
	for (int i = 0; i < MAX_ITEMS; i++) {
		items[i] = nullptr;
	}
}
Persona::~Persona() {
	//delete each item pointer from memory
	for (int i = 0; i < MAX_ITEMS; i++) {
		delete items[i];
	}
}
std::string Persona::getPersonaCode() const {
	return personaCode;
}
std::string Persona::getId() const {
	return id;
}
const Item * Persona::getItem(int posOfItem) const {
	//check if passed position is valid for array
	if (posOfItem >= 0 && posOfItem < MAX_ITEMS) {
		return items[posOfItem];
	}
	//if invalid position return nullptr
	else {
		return nullptr;
	}
}
bool Persona::addItem(std::string nItemCode, std::string nName, char nQuickKey) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		//once item pointer is nullptr create a new item object and assign it to that item pointer
		if (items[i] == nullptr) {
			items[i] = new Item(nItemCode, nName, nQuickKey);
			return true;
		}
	}
	//array is full and don't have any nullptrs
	return false;
}
bool Persona::removeItem(int posOfItem) {
	//passed position is valid and isn't nullptr
	if (getItem(posOfItem) != nullptr) {
		//delete item pointer from memory
		delete getItem(posOfItem);
		//set item pointer to nullptr
		items[posOfItem] = nullptr;
		return true;
	}
	//invalid position or is nullptr
	return false;
}
int Persona::countItems() const {
	int count = 0;
	for (int i = 0; i < MAX_ITEMS; i++) {
		//if item isn't nullptr then consider it an item
		if (items[i] != nullptr) {
			count++;
		}
	}
	return count;
}
int Persona::findByKey(char findQuickKey) const {
	for (int i = 0; i < MAX_ITEMS; i++) {
		//if item isn't nullptr and it's quickkey is same as passed key return array position
		if (items[i] != nullptr && items[i]->getQuickKey() == findQuickKey) {
			return i;
		}
	}
	//returned value if key wasn't found
	return -1;
}
void Persona::updateKey(char oldQuickKey, char newQuickKey) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		//if item isn't nullptr and it's quickkey is same as passed old key then update key to passed new key
		if (items[i] != nullptr && items[i]->getQuickKey() == oldQuickKey) {
			items[i]->updateQuickKey(newQuickKey);
		}
	}
}