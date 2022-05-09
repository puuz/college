/**
* @file Item.cpp
*
* @brief The item's constructors and functions
*
* The item's constructors and functions to add,
* remove, get, and manipulate the private data.
*
* @author Sam Farris
* @date 12/9/2021
*/

#include "Item.h"

//webcat wanted me to put curly brace like this
Item::Item(std::string nItemCode, std::string nName, char nQuickKey)
{
	if (nItemCode == "") {
		//default value if item code is empty string
		itemCode = "JNK";
	}
	else {
		itemCode = nItemCode;
	}
	if (nName == "") {
		//default value if name is empty string
		name = "Unknown";
	}
	else {
		name = nName;
	}
	if (nQuickKey < 'A' || nQuickKey > 'Z') {
		//default value if quick key is not inbetween A - Z
		quickKey = '\0';
	}
	else {
		quickKey = nQuickKey;
	}
}
std::string Item::getItemCode() const {
	return itemCode;
}
std::string Item::getName() const {
	return name;
}
char Item::getQuickKey() const {
	return quickKey;
}
void Item::updateQuickKey(char nQuickKey) {
	//if passed quickkey is inbetween A - Z or it's \0 then update quickkey to passed quickkey
	if ((nQuickKey >= 'A' && nQuickKey <= 'Z') || nQuickKey == '\0') {
		quickKey = nQuickKey;
	}
}