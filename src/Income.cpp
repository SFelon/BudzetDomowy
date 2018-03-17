#include "Income.h"

using namespace std;

Income::Income() {
idLoggedUser = 0;
incomeId = 0;
incomeDate = 0;
incomeDateString = "";
incomeName = "";
incomeAmount = 0;
}

Income::~Income() {;}


void Income::setIncomeId(int incomeId) {
this -> incomeId = incomeId;
}

int Income::getIncomeId() {
return incomeId;
}


void Income::setUserId(int userId) {
this -> idLoggedUser = userId;
}

int Income::getUserId() {
return idLoggedUser;
}


void Income::setDate(string enteredDate) {
Date date;
date.setDate(enteredDate);
this -> incomeDate = date.getDateNumber();
this -> incomeDateString = date.getDateString();
}

int Income::getDate() const {
return incomeDate;
}

string Income::getDateString() {
return incomeDateString;
}


void Income::setItemName(string itemName) {
this -> incomeName = itemName;
}

string Income::getItemName() {
return incomeName;
}


void Income::setAmount(string enteredAmount) {
Amount amount;
amount.setAmount(enteredAmount);
this -> incomeAmount = amount.getAmountNumber();
}


double Income::getAmount() {
return incomeAmount;
}




