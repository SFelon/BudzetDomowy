#include "BudgetManager.h"

using namespace std;

BudgetManager::BudgetManager(int userId) :
    incomesList(userId),
    expensesList(userId)
    {
    }

BudgetManager::~BudgetManager() {}

void BudgetManager::addNewIncome() {
incomesList.addNewIncome();
}

void BudgetManager::addNewExpense(){
expensesList.addNewExpense();
}

void BudgetManager::currentMonthBalance() {
    system("cls");
    char menuOperation = 0;
    double sumOfIncomes = incomesList.loadCurrentMonthIncomes();
    cout<<endl<<endl;
    double sumOfExpenses = expensesList.loadCurrentMonthExpenses();
    cout << endl << "      Bilans w tym miesiacu wynosi: " << sumOfIncomes - sumOfExpenses <<endl;

    cout<< endl <<"1. Powrot do menu glownego"  << endl;
    cout        <<"2. Zakoncz program"          << endl;
    cin >> menuOperation;
    if (menuOperation == '2')
        exit(0);
}

void BudgetManager::previousMonthBalance() {
    system("cls");
    char menuOperation = 0;
    double sumOfIncomes = incomesList.loadPreviousMonthIncomes();
    cout<<endl<<endl;
    double sumOfExpenses = expensesList.loadPreviousMonthExpenses();
    cout << endl << "Bilans z poprzedniego miesiaca wynosi: " << sumOfIncomes - sumOfExpenses <<endl;

    cout<< endl <<"1. Powrot do menu glownego"  << endl;
    cout        <<"2. Zakoncz program"          << endl;
    cin >> menuOperation;
    if (menuOperation == '2')
        exit(0);
}


void BudgetManager::selectedPeriodBalance() {
    char menuOperation = 0;
    do {
        system("cls");
        string firstDate, secondDate;
        Date startingDate, endDate;
        cout << "Podaj date poczatkowa (RRRR-MM-DD): " << endl;
        cin >> firstDate;
        startingDate.setDate(firstDate);
        cout << "Podaj date koncowa (RRRR-MM-DD): " << endl;
        cin >> secondDate;
        endDate.setDate(secondDate);
        cout << endl;
        double sumOfIncomes = incomesList.loadSelectedPeriodIncomes(startingDate.getDateNumber(),endDate.getDateNumber());
        cout << endl << endl;
        double sumOfExpenses = expensesList.loadSelectedPeriodExpenses(startingDate.getDateNumber(),endDate.getDateNumber());
        cout << endl << "Bilans z okresu od "<<firstDate<< " do " << secondDate <<" wynosi: "
        << sumOfIncomes - sumOfExpenses <<endl;

        cout<< endl <<"1. Ponow wyszukiwanie"  << endl;
        cout        <<"2. Powrot do menu glownego" << endl;
        cout        <<"3. Zakoncz program"         << endl;
        cin >> menuOperation;
        cin.clear();
        cin.sync();
        if (menuOperation == '3')
            exit(0);
    } while(menuOperation == '1');
}
