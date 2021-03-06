#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <windows.h>
#include <ostream>

#include "Markup.h"
#include "Income.h"


using namespace std;

class IncomesFile {

    string incomesFileName;
    int getCurrentYearMonth();
    string doubleToString(double number);

public:
    IncomesFile();
    virtual ~IncomesFile();

    int loadLastIdNumber(int& userId);
    void saveIncomeData(Income& newIncome);
    void loadCurrentMonthIncomes(int idLoggedUser, vector <Income>& incomes);
    void loadPreviousMonthIncomes(int idLoggedUser, vector <Income>& incomes);
    void loadSelectedPeriodIncomes(int idLoggedUser, vector <Income>& incomes,
                                   int startingDate, int endDate);
    void loadIncomesData(int idLoggedUser, vector <Income>& incomes);
};

#endif // INCOMESFILE_H
