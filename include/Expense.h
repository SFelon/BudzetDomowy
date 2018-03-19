#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Date.h"
#include "Amount.h"

using namespace std;

class Expense {
    int idLoggedUser;
    int expenseId;
    int expenseDate;
    string expenseDateString;
    string expenseName;
    double expenseAmount;

public:
    Expense();
    virtual ~Expense();

    int getExpenseId();
    int getUserId();
    int getDate() const;
    string getDateString();
    string getItemName();
    double getAmount();

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(string date);
    void setItemName(string itemName);
    void setAmount(string amount);
};

#endif // EXPENSE_H
