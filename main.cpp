#include <iostream>     // std::cout
#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime
#include <chrono>       // std::chrono::system_clock


#include "UserManager.h"
#include "Incomes.h"

using namespace std;


    /*string date1;
    cout << "Podaj date: " << endl;
    cin >> date1;
    Date data;
    data.setDate(date1);
    cout << data.getDate() << endl;*/


int main ()
{
  //using std::chrono::system_clock;
  time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());

  struct tm * ptm = localtime(&tt);
  cout << "Now (local time): " << put_time(ptm,"%Y-%m-%d") << '\n';

  return 0;
}



  /*  UserManager users;
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

    //AddressBook contacts(users.getidLoggedUser());
    //contacts.loadAddressBook();
    char menuOperation;

        system("cls");
        cout<<"------------------"<<endl;
        cout<<"  BUDZET DOMOWY:  "<<endl;
        cout<<"------------------"<<endl;
        cout<<"1. W budowie"<<endl;
        cout<<"2. W budowie"<<endl;
        cout<<"3. W budowie"<<endl;
        cout<<"4. W budowie"<<endl;
        cout<<"5. W budowie"<<endl;
        cout<<"6. Zmien haslo"<<endl;
        cout<<"7. Wyloguj"<<endl;
        cout<<"8. Zakoncz program"<<endl;
        cin >> menuOperation;
        switch (menuOperation) {
        case '1':
            //contacts.addNewContact();
            system("cls");
            break;
        case '2':
            //contacts.findContact();
            system("cls");
            break;
        case '3':
            //contacts.showContacts();
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
} */
