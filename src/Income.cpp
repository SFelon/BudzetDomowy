#include "Income.h"

using namespace std;

Income::Income() {
itemName = "";
}

Income::~Income() {;}

void Income::setItemName(string itemName) {
this -> itemName = itemName;
}

string Income::getItemName() {
return itemName;
}
