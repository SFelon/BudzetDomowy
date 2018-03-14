#include "Incomes.h"

using namespace std;

Incomes::Incomes(int userId) {
idLoggedUser = userId;
}

Incomes::~Incomes() {;}

void Incomes::setIncomeId(int lastIdNumber){
this -> incomeId = lastIdNumber;
}

int Incomes::getIncomeId() {
return incomeId;
}


void Incomes::setNewIncome(string date, string itemName, string amount) {
incomeDate.setDate(date);
incomeName.setItemName(itemName);
incomeAmount.setAmount(amount);
}

void Incomes::getIncome() {
cout <<getIncomeId()<<" "<< incomeDate.getDateLong() << " " << incomeName.getItemName() << " " << incomeAmount.getAmountString() << endl;
}

void Incomes::addNewIncome() {
string newDate;
string newItemName;
string newAmount;

char menuOperation = 0;
do {
        system("cls");
        cout <<"------------------"                  <<endl;
        cout <<"  BUDZET DOMOWY:  "                  <<endl;
        cout <<"------------------"                  <<endl;
        cout <<"1. Dodaj przychod z dzisiejsza data" <<endl;
        cout <<"2. Dodaj przychod z wybrana data"    <<endl;
        cin >> menuOperation;
        if (menuOperation == '1') {
            time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
            struct tm * ptm = localtime(&tt);
            stringstream dateStream;
            dateStream << put_time(ptm,"%Y-%m-%d");
            newDate = dateStream.str();
            cout << "Dzisiejsza data to: "               << newDate << endl;
            cout << "Podaj nazwe uzyskanego przychodu: " << endl;
            cin.clear(); cin.sync();
            getline(cin, newItemName);
            cout << "Podaj kwote uzyskanego przychodu: " << endl;
            cin >> newAmount;

            setIncomeId(incomeFile.loadLastIdNumber(idLoggedUser));
            setNewIncome(newDate, newItemName, newAmount);
            incomeFile.saveIncomeData(incomeId, idLoggedUser, incomeDate.getDateShort(), incomeName.getItemName(),
                                      incomeAmount.getAmountString());


            } else if ((menuOperation == '2')) {
            cout << "Podaj date uzyskania przychodu (RRRR-MM-DD): "  << endl;
            cin >> newDate;
            incomeDate.setDate(newDate);
            cout << "Podaj nazwe uzyskanego przychodu: "             << endl;
            cin.clear(); cin.sync();
            getline(cin, newItemName);
            cout << "Podaj kwote uzyskanego przychodu: "             << endl;
            cin >> newAmount;

            setIncomeId(incomeFile.loadLastIdNumber(idLoggedUser));
            incomeName.setItemName(newItemName);
            incomeAmount.setAmount(newAmount);
            incomeFile.saveIncomeData(incomeId, idLoggedUser, incomeDate.getDateShort(), incomeName.getItemName(),
                                      incomeAmount.getAmountString());
            }

        cout<< endl <<"1. Dodaj kolejny przychod"  << endl;
        cout        <<"2. Powrot do menu glownego" << endl;
        cout        <<"3. Zakoncz program"         << endl;
        cin >> menuOperation; cin.clear(); cin.sync();
        if (menuOperation == '3')
            exit(0);
    } while(menuOperation == '1');
}
