#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <algorithm>

using namespace std;


class Date
{
    int dateShort;
    string dateLong;
    int year;
    int month;
    int day;

    int convertStringToInt(string date);
    bool isValidDate(int date);

    public:
        Date();
        virtual ~Date();

    void setDate(string date);
    string getDateLong();
    int getDateShort();
};

#endif // DATE_H
