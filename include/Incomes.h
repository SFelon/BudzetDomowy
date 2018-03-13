#ifndef INCOMES_H
#define INCOMES_H

#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime
#include <chrono>       // std::chrono::system_clock
#include <sstream>

#include "IncomesFile.h"
#include "Date.h"
#include "Income.h"
#include "Amount.h"

using namespace std;

class Incomes
{
    int idLoggedUser;
    int incomeId;

    IncomesFile incomeFile;

    Date incomeDate;
    Income incomeName;
    Amount incomeAmount;

    public:
        Incomes(int userId);
        virtual ~Incomes();

    void setIncomeId(int lastIdNumber);
    int getIncomeId();

    void setNewIncome(string date, string itemName, string amount);
    void getIncome();

    void addNewIncome();
};

#endif // INCOMES_H
