#include "Amount.h"

using namespace std;

bool Amount::isValidAmount(const string& amount)
{
    try
    {
        stod(amount);
    }
    catch(...)
    {
        return false;
    }
    return true;
}

string Amount::changeCommaToDot(string amount) {
replace(amount.begin(), amount.end(), ',', '.');
return amount;
}

Amount::Amount() {
amountNumber = 0;
amountString = "";
}

Amount::~Amount() {;}

void Amount::setAmount(string amount) {
do {
if (!isValidAmount(changeCommaToDot(amount))) {
    cout << "Niepoprawna kwota. Sprobuj ponownie: " << endl;
    cin >> amount;
    }
    } while (!isValidAmount(changeCommaToDot(amount)));
this -> amountString = amount;
this -> amountNumber = atof(amount.c_str());
}

double Amount::getAmountNumber() {
return amountNumber;
}

string Amount::getAmountString() {
return amountString;
}
