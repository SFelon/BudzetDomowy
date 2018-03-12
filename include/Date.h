#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <algorithm>

using namespace std;


class Date
{
    int date;
    int year;
    int month;
    int day;

    int convertStringToInt(string date);
    bool isValidDate(int date);

    public:
        Date();
        virtual ~Date();

    void setDate(string date);
    int getDate();
};

#endif // DATE_H
