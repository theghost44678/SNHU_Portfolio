/* Anthony Shewmake */
/* 12/15/2024 */
/* Project 3 */
/* Main.cpp */

#include <fstream> // for file input/output
#include <string>
#include <vector>
#include <map> // for using the map data structure
#include <iostream>
#include "Grocery.h"
#include <iomanip>
using namespace std;


vector<Grocery> list;

std::string startHelper(int num){
    std:: string result;
    for (int i = 0; i < num; i++)
    {
        result += "*";
    }
    
    return result;
}

// function creates a backup file frequency.dat that holds all the name and quantity values
void backupData(const std::vector<Grocery>& list) {
    std::ofstream outFile("frequency.dat");  // specifies name of backup file
    if (outFile.is_open()) {
        for (auto item : list) {  // iterates through the list and adds the values to the file
            outFile << item.getItemName() << " " << item.getItemQuantity() << "\n";
        }
    } else { // print error if no file was opened
        cout << "Error creating backup file." << endl;
    }
}

// iterates through each line in file and counts the number of times each name appears in the file
std::vector<Grocery> readGroceriesFromFile(const std::string filename) {
  std::vector<Grocery> GroceriesList; // declares a list of groceries
  std::map<std::string, int> frequencyMap; // declares a map

  std::ifstream file(filename);

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) { // iterates through each lines and adds 1 each time a corresponding value is found
      frequencyMap[line]++;
    }

    for (auto pair : frequencyMap) { // constructs a Grocery object for each pairs of values
      GroceriesList.push_back({pair.first, pair.second});
    }
  } else { // output error if file not found
    std::cerr << "Error: could not open file " << filename << std::endl;
  }

  return GroceriesList; // returns the list of Grocery objects built from the input file
}

// returns the item with corresponding name 
Grocery findItem(vector<Grocery> list, std::string name){
    for (int i = 0; i<list.size(); i++) { // linear search that returns a Grocery object
        if (list[i].getItemName() == name) {
        return list[i];
        }
    }
    return Grocery("notfound", 0); // catches error if string is not found
}

int main() {
    vector<Grocery> list = readGroceriesFromFile("CS210_Project_Three_Input_File.txt"); // initializes and constructs the list
    
    backupData(list); // backs up the data
    std::string input;
    int choice;
    
    do {
        cout << "\nMenu\n";
        cout << "1. Search for an item\n";
        cout << "2. Print frequency list\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;
        switch (choice) {
            case 1: {
                std::string item;
                cout << "Enter item to search for: ";
                cin >> item;
                int index = 0;
                Grocery listItem = findItem(list, item);
                if (listItem.getItemName() == item)
                {
                    cout << listItem.getItemQuantity()<< " times" << endl;
                }
                else
                {
                    cout << "Error Item not Found" << endl;
                }
                break;
                
            }
            case 2: {
                // writes all groceries and the number of times they were mentioned in the file
                for(auto item : list)
                {
                    cout << setw(12) << item.getItemName() << setw(5) << item.getItemQuantity() << endl;
                    
                }
                break;
            }
            // writes all groceries and the number of times they were mentioned in the file but using "*" symbol
            case 3: {
                for(auto item: list)
                    cout << item.getItemName() << " " << startHelper(item.getItemQuantity()) << endl;
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: { // catches invalid input
                cout << "Invalid choice. Try again.\n";
                continue;
            }
        }
    } while (choice != 4);
}
