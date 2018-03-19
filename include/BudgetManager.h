#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "Incomes.h"

using namespace std;

class BudgetManager {
    Incomes incomesList;

    public:
        BudgetManager(int userId);
        virtual ~BudgetManager();

    void addNewIncome();
    void currentMonthBalance();
    void previousMonthBalance();
    void selectedPeriodBalance();
};

#endif // BUDGETMANAGER_H
