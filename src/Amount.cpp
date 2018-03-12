#include "Amount.h"

using namespace std;

double Amount::changeCommaToDot(string amountToCheck) {
replace(amountToCheck.begin(), amountToCheck.end(), ',', '.');
return  atof(amountToCheck.c_str());
}

Amount::Amount() {
amount = 0;
}

Amount::~Amount() {;}

void Amount::setAmount(string amount) {
this -> amount = changeCommaToDot(amount);
}

double Amount::getAmount() {
return amount;
}

