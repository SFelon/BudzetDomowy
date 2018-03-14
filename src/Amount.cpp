#include "Amount.h"

using namespace std;

string Amount::changeCommaToDot(string amountToCheck) {
replace(amountToCheck.begin(), amountToCheck.end(), ',', '.');
return amountToCheck;
}

Amount::Amount() {
amountNumber = 0;
amountString = "";
}

Amount::~Amount() {;}

void Amount::setAmount(string amount) {
string tempNumber;
tempNumber = changeCommaToDot(amount);
this -> amountString = tempNumber;
this -> amountNumber = atof(tempNumber.c_str());
}

double Amount::getAmountNumber() {
return amountNumber;
}

string Amount::getAmountString() {
return amountString;
}
