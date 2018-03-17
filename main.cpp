#include <iostream>
#include "UserManager.h"
#include "Incomes.h"

using namespace std;

int main () {
    UserManager users;
    UsersFile newUserFile;
    newUserFile.loadUsersData(users.getUsersData());
    char mainMenuOperation;

    while(true) {
    if ( users.getidLoggedUser() == 0 ) {
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
            users.registerNewUser();
            system("cls");
            break;
        case '2':
            users.loginUser();
            system("cls");
            break;
        case '9':
            exit(0);
            break;
        }
    }  else if (users.getidLoggedUser() > 0) {
    Incomes income(users.getidLoggedUser());
    char menuOperation;

        system("cls");
        cout<<"------------------"<<endl;
        cout<<"  BUDZET DOMOWY:  "<<endl;
        cout<<"------------------"<<endl;
        cout<<"1. Dodaj nowy przychod"<<endl;
        cout<<"2. W budowie"<<endl;
        cout<<"3. W budowie"<<endl;
        cout<<"4. W budowie"<<endl;
        cout<<"5. W budowie"<<endl;
        cout<<"6. Zmien haslo"<<endl;
        cout<<"7. Wyloguj"<<endl;
        cout<<"8. Zakoncz program"<<endl;
        cin.sync();
        cin >> menuOperation;
        switch (menuOperation) {
        case '1': {
            income.addNewIncome();
            system("cls");
            break;
            }
        case '2': {
            income.loadCurrentMonthIncomes();
            system("cls");
            break;
            }
        case '3':
            income.loadPreviousMonthIncomes();
            system("cls");
            break;
        case '4':
            //contacts.changeContactData();
            system("cls");
            break;
        case '5':
           // contacts.eraseContact();
            system("cls");
            break;
        case '6':
            users.changePassword();
            system("cls");
            break;
        case '7':
            users.setidLoggedUser(0);
            break;
        case '8':
            exit(0);
        }
    }
}
  return 0;
}
