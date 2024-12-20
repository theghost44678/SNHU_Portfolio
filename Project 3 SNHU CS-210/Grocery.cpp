/* Anthony Shewmake */
/* 12/15/2024 */
/* Project 3 */
/* Grocery.cpp */

#include "Grocery.h"

using namespace std;

// Constructor
Grocery::Grocery(string itemName, int itemQuantity) {
    name = itemName;
    quantity = itemQuantity;
}

// Accessors
std::string Grocery::getItemName() {
    return name;
}

int Grocery::getItemQuantity() {
    return quantity;
}

// Mutators
void Grocery::setItemName(std::string itemName) {
    name = itemName;
}

void Grocery::setItemQuantity(int itemQuantity) {
    quantity = itemQuantity;
}

