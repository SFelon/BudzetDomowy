#include "Incomes.h"

using namespace std;

void Incomes::showIncomeData(Income income)
{
    cout << "IncomeID: "<< income.getIncomeId()  << endl;
    cout << "UserID "   << income.getUserId()    << endl;
    cout << "Data: "    << income.getDateString()<< endl;
    cout << "Nazwa: "   << income.getItemName()  << endl;
    cout << "Kwota: "   << income.getAmount()    << endl << endl;
}

string Incomes::getCurrentDate() {
time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
struct tm * ptm = localtime(&tt);
stringstream dateStream;
dateStream << put_time(ptm,"%Y-%m-%d");
string currentDate = dateStream.str();
return currentDate;
}


Incomes::Incomes(int userId) {
idLoggedUser = userId;
}

Incomes::~Incomes() {;}


void Incomes::addNewIncome() {

Income newIncome;
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

            newIncome.setIncomeId(incomeFile.loadLastIdNumber(idLoggedUser));
            newIncome.setUserId(idLoggedUser);

            newDate = getCurrentDate();
            cout << "Dzisiejsza data to: "               << newDate << endl;
            newIncome.setDate(newDate);
            cout << "Podaj nazwe uzyskanego przychodu: " << endl;
            cin.clear(); cin.sync();
            getline(cin, newItemName);
            newIncome.setItemName(newItemName);
            cout << "Podaj kwote uzyskanego przychodu: " << endl;
            cin >> newAmount;
            newIncome.setAmount(newAmount);
            incomeFile.saveIncomeData(newIncome);


            } else if ((menuOperation == '2')) {

            newIncome.setIncomeId(incomeFile.loadLastIdNumber(idLoggedUser));
            newIncome.setUserId(idLoggedUser);

            cout << "Podaj date uzyskania przychodu (RRRR-MM-DD): "  << endl;
            cin >> newDate;
            newIncome.setDate(newDate);
            cout << "Podaj nazwe uzyskanego przychodu: "             << endl;
            cin.clear(); cin.sync();
            getline(cin, newItemName);
            newIncome.setItemName(newItemName);
            cout << "Podaj kwote uzyskanego przychodu: "             << endl;
            cin >> newAmount;
            newIncome.setAmount(newAmount);

            incomeFile.saveIncomeData(newIncome);
            }

        cout<< endl <<"1. Dodaj kolejny przychod"  << endl;
        cout        <<"2. Powrot do menu glownego" << endl;
        cout        <<"3. Zakoncz program"         << endl;
        cin >> menuOperation; cin.clear(); cin.sync();
        if (menuOperation == '3')
            exit(0);
    } while(menuOperation == '1');
}

void Incomes::loadCurrentMonthIncomes() {
incomeFile.loadCurrentMonthIncomes(idLoggedUser,incomes);

sort( incomes.begin( ), incomes.end( ), [ ]( const Income& lhs, const Income& rhs )
{
   return lhs.getDate() < rhs.getDate();
});



vector <Income> ::iterator it;
for ( it = incomes.begin(); it != incomes.end(); ++it) {
        showIncomeData(*it);
}

Sleep(5000);
}

void Incomes::loadPreviousMonthIncomes() {
incomeFile.loadPreviousMonthIncomes(idLoggedUser,incomes);

sort( incomes.begin( ), incomes.end( ), [ ]( const Income& lhs, const Income& rhs )
{
   return lhs.getDate() < rhs.getDate();
});



vector <Income> ::iterator it;
for ( it = incomes.begin(); it != incomes.end(); ++it) {
        showIncomeData(*it);
}

Sleep(5000);
}
