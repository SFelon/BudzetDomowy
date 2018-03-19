#ifndef EXPENSES_H
#define EXPENSES_H

#include <vector>
#include "ExpensesFile.h"
#include "Expense.h"

using namespace std;

class Expenses {
    int idLoggedUser;
    ExpensesFile expenseFile;
    vector <Expense> expenses;

    void showExpenseData(Expense expense);
    double printSortedExpensesInTable(vector <Expense> &expenses);
    string getCurrentDate();

public:
    Expenses(int userId);
    virtual ~Expenses();

    void addNewExpense();
    double loadCurrentMonthExpenses();
    double loadPreviousMonthExpenses();
    double loadSelectedPeriodExpenses(int startingDate, int endDate);
};

#endif // EXPENSES_H
