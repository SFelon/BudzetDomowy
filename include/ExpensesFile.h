#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H


#include <iostream>
#include <windows.h>
#include <ostream>

#include "Markup.h"
#include "Expense.h"


using namespace std;

class ExpensesFile {

    string expensesFileName;
    int getCurrentYearMonth();
    string doubleToString(double number);

public:
    ExpensesFile();
    virtual ~ExpensesFile();

    int loadLastIdNumber(int& userId);
    void saveExpenseData(Expense& newExpense);
    void loadCurrentMonthExpenses(int idLoggedUser, vector <Expense>& expenses);
    void loadPreviousMonthExpenses(int idLoggedUser, vector <Expense>& expenses);
    void loadSelectedPeriodExpenses(int idLoggedUser, vector <Expense>& expenses,
                                   int startingDate, int endDate);
    void loadExpensesData(int idLoggedUser, vector <Expense>& expenses);
};
#endif // EXPENSESFILE_H
