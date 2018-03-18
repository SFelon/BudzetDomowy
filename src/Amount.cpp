#include "Amount.h"

using namespace std;

string Amount::changeCommaToDot(string amount) {
    replace(amount.begin(), amount.end(), ',', '.');
    return amount;
}

bool Amount::isValidAmount(const string& amount) {
    int nb_point = 0;
    for (int i=0; i < amount.length(); i++) {
        if (amount[i] == '.') {
            nb_point++;
        } else if (!isdigit(amount[i]) || (amount[0] == '0')) {
            return false;
        }
    }
    if (nb_point <= 1) {
        return true;
    } else {
        return false;
    }
}


Amount::Amount() {
    amountNumber = 0;
}

Amount::~Amount() {;}

void Amount::setAmount(string amount) {
    do {
        if (!isValidAmount(changeCommaToDot(amount))) {
            cout << "Niepoprawna kwota. Sprobuj ponownie: " << endl;
            cin >> amount;
        }
    } while (!isValidAmount(changeCommaToDot(amount)));
    this -> amountNumber = stod(amount.c_str());
}

double Amount::getAmountNumber() {
    return amountNumber;
}

