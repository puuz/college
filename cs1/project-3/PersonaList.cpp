/**
* @file PersonaList.cpp
*
* @brief The persona list constructors and functions.
*
* The persona list constructors and functions to add,
* remove, get, and manipulate the private data.
*
* @author Sam Farris
* @date 12/14/2021
*/

#include "PersonaList.h"

PersonaList::PersonaList()
//webcat wanted it like this
{
	//creates persona array of 5
	personas = new Persona[5];
	size = 5;
	count = 0;
}
PersonaList::~PersonaList() {
	//deletes persona array from memory
	delete [] personas;
}
int PersonaList::getPersonaCount() const {
	return count;
}
Persona * PersonaList::getPersona(int posOfPersona) {
	//check if position is valid otherwise return nullptr
	if (posOfPersona >= 0 && posOfPersona < count) {
		return &personas[posOfPersona];
	}
	else {
		return nullptr;
	}
}
const Persona * PersonaList::getPersona(int posOfPersona) const {
	//check if position is valid otherwise return nullptr
	if (posOfPersona >= 0 && posOfPersona < count) {
		return &personas[posOfPersona];
	}
	else {
		return nullptr;
	}
}
void PersonaList::addPersona(Persona p) {
	//grow array if the count and size is the same meaning the array is full
	if (count == size) {
		growArray();
	}
	//add new persona whether or not array is full or not because it won't be anymore if it was
	//++ adds after declaration
	personas[count++] = p;
}
void PersonaList::growArray() {
	//create new array that is double the size which will replace the previous
	Persona* newData = new Persona[size * 2];
	//loop over to move all the personas to the new array
	for (int i = 0; i < size; i++) {
		newData[i] = personas[i];
	}
	//delete old personas array from memory 
	delete [] personas;
	//assing new array to personas, changing the pointer
	personas = newData;
	//fix the size because array grew
	size *= 2;
}
Persona * PersonaList::findPersona(std::string findId) {
	for (int i = 0; i < count; i++) {
		//once the passed id is found in a persona return that persona
		if (findId == getPersona(i)->getId()) {
			return getPersona(i);
		}
	}
	//if no persona found return nullptr
	return nullptr;
}
/** the return int of there being no quick key */
const int NO_QUICK_KEY = -1;
int PersonaList::resetKeyBindings(char resetQuickKey) {
	int changed = 0;
	for (int i = 0; i < count; i++) {
		//once passed quick key is found update that quick key with the default
		if (getPersona(i)->findByKey(resetQuickKey) != NO_QUICK_KEY) {
			getPersona(i)->updateKey(resetQuickKey, '\0');
			//change the number of times a list has been changed
			changed++;
		}
	}
	return changed;
}
void PersonaList::resetList() {
	count = 0;
}