#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    string itemName;
    public:
        Income();
        virtual ~Income();

    void setItemName(string itemName);
    string getItemName();
};

#endif // INCOME_H
