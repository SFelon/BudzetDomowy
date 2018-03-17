#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Date.h"
#include "Amount.h"

using namespace std;

class Income
{
    int idLoggedUser;
    int incomeId;
    int incomeDate;
    string incomeDateString;
    string incomeName;
    double incomeAmount;

    public:
        Income();
        virtual ~Income();

    void setItemName(string itemName);
    string getItemName();

    int getIncomeId();
    int getUserId();
    int getDate() const;
    string getDateString();
    string getItem();
    double getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(string amount);
};

#endif // INCOME_H
