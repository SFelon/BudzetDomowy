#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Amount
{
    double amountNumber;

    bool isValidAmount(const string& amount);
    string changeCommaToDot(string amount);

    public:
        Amount();
        virtual ~Amount();

    void setAmount(string amount);
    double getAmountNumber();
};

#endif // AMOUNT_H
