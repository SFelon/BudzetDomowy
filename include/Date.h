#ifndef DATE_H
#define DATE_H

#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>

#include <iostream>
#include <algorithm>

using namespace std;

class Date
{
    string date;

    int convertStringToInt(string date);
    bool isValidDate(int date);

    public:
        Date();
        virtual ~Date();

    void setDate(string date);
    string getDateString();
    int getDateNumber();
};

#endif // DATE_H
