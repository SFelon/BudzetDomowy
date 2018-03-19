#include "Expense.h"

Expense::Expense() {
    idLoggedUser = 0;
    expenseId = 0;
    expenseDate = 0;
    expenseDateString = "";
    expenseName = "";
    expenseAmount = 0;
}

Expense::~Expense() {;}


void Expense::setExpenseId(int expenseId) {
    this -> expenseId = expenseId;
}

int Expense::getExpenseId() {
    return expenseId;
}


void Expense::setUserId(int userId) {
    this -> idLoggedUser = userId;
}

int Expense::getUserId() {
    return idLoggedUser;
}


void Expense::setDate(string enteredDate) {
    Date date;
    date.setDate(enteredDate);
    this -> expenseDate = date.getDateNumber();
    this -> expenseDateString = date.getDateString();
}

int Expense::getDate() const {
    return expenseDate;
}

string Expense::getDateString() {
    return expenseDateString;
}


void Expense::setItemName(string itemName) {
    this -> expenseName = itemName;
}

string Expense::getItemName() {
    return expenseName;
}


void Expense::setAmount(string enteredAmount) {
    Amount amount;
    amount.setAmount(enteredAmount);
    this -> expenseAmount = amount.getAmountNumber();
}

double Expense::getAmount() {
    return expenseAmount;
}
