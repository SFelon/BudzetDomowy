#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Date.h"
#include "Amount.h"

using namespace std;

class Income {
    int idLoggedUser;
    int incomeId;
    int incomeDate;
    string incomeDateString;
    string incomeName;
    float incomeAmount;

public:
    Income();
    virtual ~Income();

    int getIncomeId();
    int getUserId();
    int getDate() const;
    string getDateString();
    string getItemName();
    float getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(string date);
    void setItemName(string itemName);
    void setAmount(string amount);
};

#endif // INCOME_H
