#include "Incomes.h"

using namespace std;

Incomes::Incomes() {;}

Incomes::~Incomes() {;}

void Incomes::setNewIncome(string date, string itemName, string amount) {
this -> incomeDate.setDate(date);
this -> incomeName.setItemName(itemName);
this -> incomeAmount.setAmount(amount);
}

string Incomes::getIncome() {
cout << incomeDate.getDate() << " " << incomeName.getItemName() << " " << incomeAmount.getAmount() << endl;
}
