#ifndef INCOMES_H
#define INCOMES_H

#include "Date.h"
#include "Income.h"
#include "Amount.h"

using namespace std;

class Incomes
{
    Date incomeDate;
    Income incomeName;
    Amount incomeAmount;

    public:
        Incomes();
        virtual ~Incomes();

    void setNewIncome(string date, string itemName, string amount);

};

#endif // INCOMES_H
