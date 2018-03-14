#include "Date.h"

using namespace std;

int Date::convertStringToInt(string date) {
date.erase(remove(date.begin(), date.end(), '-'), date.end());
return atoi(date.c_str());
}

bool Date::isValidDate(int date) {

int day = date % 100;
int month = (date % 10000)/100;
int year = date / 10000;


const int MIN_VALID_YR = 2000;
int MAX_VALID_YR;
int MAX_VALID_MNT;

time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
struct tm * ptm = localtime(&tt);
stringstream dateStream;
dateStream << put_time(ptm,"%Y");
    MAX_VALID_YR = stoi(dateStream.str());
dateStream.str(string());
dateStream <<  put_time(ptm,"%m");
    MAX_VALID_MNT = stoi(dateStream.str());


    if (year > MAX_VALID_YR || year < MIN_VALID_YR)
      return false;
    if (year == MAX_VALID_YR && month > MAX_VALID_MNT)
      return false;
    if (month < 1 || month > 12)
      return false;
    if (day < 1 || day > 31)
      return false;

    if (month == 2) {
        if ((((year%4 == 0) && (year%100!=0)) || (year%400 == 0)))
           return (day <= 29);
        else
           return (day <= 28);
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);

    return true;
}

Date::Date() {
dateShort = 0;
dateLong = "";
}

Date::~Date() {;}

void Date::setDate(string date) {
do {
    if(!isValidDate(convertStringToInt(date))) {
    cout << "Bledna data. Wprowadz ponownie: " << endl;
    cin >> date;
    }
    } while(!isValidDate(convertStringToInt(date)));
    this -> dateLong  = date;
    this -> dateShort = convertStringToInt(date);
}

string Date::getDateLong() {
return dateLong;
}

int Date::getDateShort() {
return dateShort;
}
