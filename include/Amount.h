#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Amount
{
    string amountString;
    double amountNumber;
    string changeCommaToDot(string amountToCheck);

    public:
        Amount();
        virtual ~Amount();

    void setAmount(string amount);
    double getAmountNumber();
    string getAmountString();
};

#endif // AMOUNT_H
