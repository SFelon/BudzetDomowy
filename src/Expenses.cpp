#include "Expenses.h"

using namespace std;

void Expenses::showExpenseData(Expense expense) {
    string date = expense.getDateString();
    string name = expense.getItemName();
    double amount = expense.getAmount();
    printf(" %-11s| %-20s| %c%.2f \n",
           date.c_str(),
           name.c_str(),
           '-',
           amount);
}


double Expenses::printSortedExpensesInTable(vector <Expense> &expenses) {

    sort( expenses.begin( ), expenses.end( ), [ ]( const Expense& lhs, const Expense& rhs ) {
        return lhs.getDate() < rhs.getDate();
    });

    vector <Expense> ::iterator it;
    double sumOfExpenses = 0;
    cout <<"------------------WYDATKI-------------------"<<endl;
    printf(" %-11s| %-20s| %-8s \n", "Data", "Nazwa", "Kwota");
    cout <<"--------------------------------------------"<<endl;
    for ( it = expenses.begin(); it != expenses.end(); ++it) {
        showExpenseData(*it);
        sumOfExpenses += it -> getAmount();
    }
    cout <<"--------------------------------------------"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout << "              Suma wydatkow wynosi: " << "-" << fixed << setprecision(2) << sumOfExpenses << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    return sumOfExpenses;
}


string Expenses::getCurrentDate() {
    time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
    struct tm * ptm = localtime(&tt);
    stringstream dateStream;
    dateStream << put_time(ptm,"%Y-%m-%d");
    string currentDate = dateStream.str();
    return currentDate;
}


Expenses::Expenses(int userId) {
    idLoggedUser = userId;
}

Expenses::~Expenses() {;}


void Expenses::addNewExpense() {

    Expense newExpense;
    string newDate;
    string newItemName;
    string newAmount;


    char menuOperation = 0;
    do {
        system("cls");
        cout <<"------------------"                  <<endl;
        cout <<"  BUDZET DOMOWY:  "                  <<endl;
        cout <<"------------------"                  <<endl;
        cout <<"1. Dodaj wydatek z dzisiejsza data" <<endl;
        cout <<"2. Dodaj wydatek z wybrana data"    <<endl;
        cin >> menuOperation;
        if (menuOperation == '1') {

            newExpense.setExpenseId(expenseFile.loadLastIdNumber(idLoggedUser));
            newExpense.setUserId(idLoggedUser);

            newDate = getCurrentDate();
            cout << "Dzisiejsza data to: "               << newDate << endl;
            newExpense.setDate(newDate);
            cout << "Podaj nazwe ponieionego wydatku: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, newItemName);
            newExpense.setItemName(newItemName);
            cout << "Podaj kwote poniesionego wydatku: " << endl;
            cin >> newAmount;
            newExpense.setAmount(newAmount);
            expenseFile.saveExpenseData(newExpense);


        } else if ((menuOperation == '2')) {

            newExpense.setExpenseId(expenseFile.loadLastIdNumber(idLoggedUser));
            newExpense.setUserId(idLoggedUser);

            cout << "Podaj date poniesienia wydatku (RRRR-MM-DD): "  << endl;
            cin >> newDate;
            newExpense.setDate(newDate);
            cout << "Podaj nazwe poniesionego wydatku: "             << endl;
            cin.clear();
            cin.sync();
            getline(cin, newItemName);
            newExpense.setItemName(newItemName);
            cout << "Podaj kwote poniesionego wydatku: "             << endl;
            cin >> newAmount;
            newExpense.setAmount(newAmount);

            expenseFile.saveExpenseData(newExpense);
        }

        cout<< endl <<"1. Dodaj kolejny wydatek"  << endl;
        cout        <<"2. Powrot do menu glownego" << endl;
        cout        <<"3. Zakoncz program"         << endl;
        cin >> menuOperation;
        cin.clear();
        cin.sync();
        if (menuOperation == '3')
            exit(0);
    } while(menuOperation == '1');
}

double Expenses::loadCurrentMonthExpenses() {
    expenses.clear();
    expenseFile.loadCurrentMonthExpenses(idLoggedUser,expenses);
    return printSortedExpensesInTable(expenses);
}

double Expenses::loadPreviousMonthExpenses() {
    expenses.clear();
    expenseFile.loadPreviousMonthExpenses(idLoggedUser,expenses);
    return printSortedExpensesInTable(expenses);
}

double Expenses::loadSelectedPeriodExpenses(int startingDate, int endDate) {
    expenses.clear();
    expenseFile.loadSelectedPeriodExpenses(idLoggedUser,expenses,startingDate, endDate);
    return printSortedExpensesInTable(expenses);
}

