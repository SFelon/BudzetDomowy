#include "Incomes.h"

using namespace std;

Incomes::Incomes() {;}

Incomes::~Incomes() {;}

void Incomes::setNewIncome(string date, string itemName, string amount) {
incomeDate.setDate(date);
incomeName.setItemName(itemName);
incomeAmount.setAmount(amount);
}
