#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Amount {
    float amountNumber;

    bool isValidAmount(const string& amount);
    string changeCommaToDot(string amount);

public:
    Amount();
    virtual ~Amount();

    void setAmount(string amount);
    float getAmountNumber();
};

#endif // AMOUNT_H
