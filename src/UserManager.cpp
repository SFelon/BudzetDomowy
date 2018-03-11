#include <iostream>
#include <windows.h>
#include <cstdlib>

#include "UserManager.h"
#include "Markup.h"

using namespace std;

////////////////////////////////////////////
int UserManager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getID() + 1;
}

////////////////////////////////////////////


UserManager::UserManager() {;}

UserManager::~UserManager() {;}

////////////////////////////////////////////

int UserManager::getidLoggedUser() {
    return idLoggedUser;
}

void UserManager::setidLoggedUser(int id) {
    idLoggedUser = id;
}

vector <User>& UserManager::getUsersData(){
        return this->users;
}

//////////////////////////////////////////////

void UserManager::registerNewUser()
{
User newUser;
UsersFile usersFile;
string name, surname, login, password;

cout << "Podaj swoje imie: ";
cin >> name;

cout << "Podaj swoje nazwisko: ";
cin >> surname;

cout << "Podaj nowy login uzytkownika: ";
cin >> login;

vector <User> ::iterator it;
    for (it = users.begin(); it != users.end(); it++) {
        if (it -> getLogin() == login) {
            cout << "Podany login jest juz wykorzystany. Wybierz inny: ";
            cin >> login;
            it = users.begin();
        }
    }
cout << "Podaj haslo: ";
cin >> password;

newUser.setID(getNewUserID());
newUser.setName(name);
newUser.setSurname(surname);
newUser.setLogin(login);
newUser.setPassword(password);
users.push_back(newUser);
usersFile.saveUsersData(newUser);

cout<<"Konto zalozone"<<endl;
Sleep(1000);
}

////////////////////////////////////////////
void UserManager::loginUser()
{
    string login, password;
    cout << "Podaj login: ";
    cin >> login;
    vector <User> ::iterator it;
    for (it = users.begin(); it != users.end(); it++) {
        if (it->getLogin() == login) {
            for(int j=0; j<3; j++) {
                cout<<"Podaj haslo. Pozostalo prob: "<<3-j<<endl;
                cin >> password;
                if ( users[(it - users.begin())].getPassword() == password ) {
                    cout<<"Zalogowales sie."<<endl;
                    Sleep(1000);
                    idLoggedUser = users[(it - users.begin())].getID();
                    return;
                }
            }
            cout<<"Podales 3 razy bledne haslo. Poczekaj";
            Sleep(3000);
            idLoggedUser = 0;
            return;
        }
    }
    cout<<"Uzytkownik o podanym loginie nie istnieje"<<endl;
    Sleep(1500);
    idLoggedUser = 0;
    return;
}
////////////////////////////////////////////

void UserManager::changePassword() {
    UsersFile usersFile;
    string password;
    cout<<"Podaj nowe haslo: ";
    cin >> password;
    vector <User> ::iterator it;
    for (it = users.begin(); it != users.end(); it++) {
        if (it -> getID() == idLoggedUser) {
        users[(it - users.begin())].setPassword(password);
        usersFile.changeUsersPassword(idLoggedUser, password);
        break;
        }
    }
}
