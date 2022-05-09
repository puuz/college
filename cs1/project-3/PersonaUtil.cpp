/**
* @file PersonaUtil.cpp
*
* @brief The persona util constructors and functions.
*
* The persona util constructors and functions to add,
* remove, get, and manipulate the private data.
*
* @author Sam Farris
* @date 12/14/2021
*/

#include "PersonaUtil.h"

PersonaUtil::PersonaUtil(PersonaList * nList)
//webcat wanted it like this
{
	list = nList;
}
PersonaList * PersonaUtil::getPersonas() {
	//the personas list to manipulate
	return list;
}
void PersonaUtil::personaCommand(std::istream & in) {
	//read in new persona and add it to the list
	Persona readPersona;
	in >> readPersona;
	list->addPersona(readPersona);
}
void PersonaUtil::addItemCommand(std::istream & in) {
	std::string personaId;
	std::string nItemCode;
	std::string nName;
	char nQuickKey;
	in >> personaId >> nItemCode >> nName >> nQuickKey;
	//if persona for the persona id is not nullptr in the list add the item with the read in data
	if (list->findPersona(personaId) != nullptr) {
		list->findPersona(personaId)->addItem(nItemCode, nName, nQuickKey);
	}
}
void PersonaUtil::removeItemCommand(std::istream & in) {
	std::string personaId;
	int itemSlotToClear;
	in >> personaId >> itemSlotToClear;
	//if persona for the the persona id is not nullptr in the list remove the item with the read in slot to clear
	if (list->findPersona(personaId) != nullptr) {
		list->findPersona(personaId)->removeItem(itemSlotToClear);
	}
}
void PersonaUtil::loadPersonas(std::istream & in) {
	if (list == nullptr) {
		return;
	}
	//first reset the list before loading one
	list->resetList();
	//read commands until a command is incorrect or the input fails
	while (in.good()) {
		std::string command;
		in >> command;
		if (command == "persona") {
			personaCommand(in);
		}
		else if (command == "additem") {
			addItemCommand(in);
		}
		else if (command == "removeitem") {
			removeItemCommand(in);
		}
		else {
			return;
		}
	}
}
std::string PersonaUtil::savePersonas() {
	std::stringstream readSS;
	//emptry string if list is nullptr
	if (list == nullptr) {
		return "";
	}
	//print out the persona in the list for the position in the loop each time
	for (int i = 0; i < list->getPersonaCount(); i++) {
		readSS << "persona " << *list->getPersona(i) << "\n";
	}
	//return the str from the string stream buffer
	return readSS.str();
}
std::string PersonaUtil::clearKeys(char quickKeys[], int keysSize) {
	//no personas available if list is nullptr
	if (list == nullptr) {
		return "No personas available";
	}
	std::stringstream readSS;
	readSS << "Keys Cleared\n";
	//clear keys for the passed size amount of times
	for (int i = 0; i < keysSize; i++) {
		readSS << quickKeys[i] << "\t";
		//reset the current position in the array of the quick key
		int changed = list->resetKeyBindings(quickKeys[i]);
		//write to the strea none if nothing changed or number of times changed if it did
		if (changed == 0) {
			readSS << "None\n";
		}
		else {
			readSS << changed << "\n";
		}
	}
	//return the str from the string stream buffer
	return readSS.str();
}