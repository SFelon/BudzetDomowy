#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <windows.h>

#include "Markup.h"

using namespace std;

class IncomesFile
{
    string incomesFileName;
    public:
        IncomesFile();
        virtual ~IncomesFile();

    int loadLastIdNumber(int& userId);
    void loadIncomesData();
    void saveIncomeData(int& incomeId, int& userId, int date, string name, double amount);
};

#endif // INCOMESFILE_H
