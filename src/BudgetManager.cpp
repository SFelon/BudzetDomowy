#include "BudgetManager.h"

using namespace std;

BudgetManager::BudgetManager(int userId) :
    incomesList(userId)
    {
    }

BudgetManager::~BudgetManager() {}

void BudgetManager::currentMonthBalance() {
    char menuOperation = 0;
    incomesList.loadCurrentMonthIncomes();

    cout<< endl <<"1. Powrot do menu glownego"  << endl;
    cout        <<"2. Zakoncz program"          << endl;
    cin >> menuOperation;
    if (menuOperation == '2')
        exit(0);
}

void BudgetManager::previousMonthBalance() {
    char menuOperation = 0;
    incomesList.loadPreviousMonthIncomes();

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
        incomesList.loadSelectedPeriodIncomes(startingDate.getDateNumber(),endDate.getDateNumber());

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
