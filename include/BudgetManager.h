#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class BudgetManager {
    Incomes incomesList;
    Expenses expensesList;

    public:
        BudgetManager(int userId);
        virtual ~BudgetManager();

    void addNewIncome();
    void addNewExpense();
    void currentMonthBalance();
    void previousMonthBalance();
    void selectedPeriodBalance();
};

#endif // BUDGETMANAGER_H
