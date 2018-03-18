#ifndef INCOMES_H
#define INCOMES_H

#include <vector>
#include "IncomesFile.h"
#include "Income.h"


using namespace std;

class Incomes
{
    int idLoggedUser;
    IncomesFile incomeFile;
    vector <Income> incomes;

    void showIncomeData(Income income);
    void printSortedIncomesInTable(vector <Income> &incomes);
    string getCurrentDate();

public:
    Incomes(int userId);
    virtual ~Incomes();

    void addNewIncome();
    void loadCurrentMonthIncomes();
    void loadPreviousMonthIncomes();
    void loadSelectedPeriodIncomes(int startingDate, int endDate);
};

#endif // INCOMES_H
