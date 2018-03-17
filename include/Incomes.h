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

    string getCurrentDate();
    void showIncomeData(Income income);

    public:
        Incomes(int userId);
        virtual ~Incomes();


    void addNewIncome();
    void loadCurrentMonthIncomes();
    void loadPreviousMonthIncomes();
};

#endif // INCOMES_H
