#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Amount
{
    double amount;
    double changeCommaToDot(string amountToCheck);

    public:
        Amount();
        virtual ~Amount();

    void setAmount(string amount);
    double getAmount();
};

#endif // AMOUNT_H
