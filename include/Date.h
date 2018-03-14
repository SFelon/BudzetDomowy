#ifndef DATE_H
#define DATE_H

#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime
#include <chrono>       // std::chrono::system_clock
#include <sstream>

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
