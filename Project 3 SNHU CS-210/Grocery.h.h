/* Anthony Shewmake */
/* 12/15/2024 */
/* Project 3 */ 
/* Grocery.H */ 


#ifndef GROCERY_H
#define GROCERY_H

#include <string>

class Grocery {
public:
    // Constructor
    Grocery(std::string name, int quantity);
    // Accessors
    std::string getItemName();

    int getItemQuantity();

    // Mutators
    void setItemName(std::string itemName);
    void setItemQuantity(int itemQuantity);

private:
    std::string name;
    int quantity;
};

#endif
