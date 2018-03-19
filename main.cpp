#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

int main () {
    UserManager userManager;
    char mainMenuOperation;
    while(true) {
    if ( userManager.getidLoggedUser() == 0 ) {
        system("cls");
        cout<<"------------------"<<endl;
        cout<<"  BUDZET DOMOWY:  "<<endl;
        cout<<"------------------"<<endl;
        cout<<"1. Rejestracja"<<endl;
        cout<<"2. Logowanie"<<endl;
        cout<<"9. Zakoncz Program"<<endl;
        cin >> mainMenuOperation;
        switch(mainMenuOperation) {
        case '1':
            userManager.registerNewUser();
            system("cls");
            break;
        case '2':
            userManager.loginUser();
            system("cls");
            break;
        case '9':
            exit(0);
            break;
        }
    }  else if (userManager.getidLoggedUser() > 0) {
    BudgetManager budgetManager(userManager.getidLoggedUser());
    char menuOperation;

        system("cls");
        cout<<"------------------"<<endl;
        cout<<"  BUDZET DOMOWY:  "<<endl;
        cout<<"------------------"<<endl;
        cout<<"1. Dodaj nowy przychod"<<endl;
        cout<<"2. Dodaj nowy wydatek"<<endl;
        cout<<"3. Wyswietl bilans z obecnego miesiaca"<<endl;
        cout<<"4. Wyswietl bilans z poprzedniego miesiaca"<<endl;
        cout<<"5. Wyswietl bilans z wybranego okreu"<<endl;
        cout<<"6. Zmien haslo"<<endl;
        cout<<"7. Wyloguj"<<endl;
        cout<<"8. Zakoncz program"<<endl;
        cin.sync();
        cin >> menuOperation;
        switch (menuOperation) {
        case '1': {
            budgetManager.addNewIncome();
            system("cls");
            break;
            }
        case '2': {
            budgetManager.addNewExpense();
            system("cls");
            break;
            }
        case '3':
            budgetManager.currentMonthBalance();
            system("cls");
            break;
        case '4':
            budgetManager.previousMonthBalance();
            system("cls");
            break;
        case '5':
            budgetManager.selectedPeriodBalance();
            system("cls");
            break;
        case '6':
            userManager.changePassword();
            system("cls");
            break;
        case '7':
            userManager.setidLoggedUser(0);
            break;
        case '8':
            exit(0);
        }
    }
}
  return 0;
}
