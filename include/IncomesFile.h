#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class IncomesFile
{
    string incomesFileName;
    public:
        IncomesFile();
        virtual ~IncomesFile();

    int loadLastIdNumber(int userId);
    void loadIncomesData();
    void saveIncomeData();
};

#endif // INCOMESFILE_H
