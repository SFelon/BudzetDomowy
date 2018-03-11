#include "User.h"
#include <iostream>
#include <algorithm>

using namespace std;

string User::changeFirstLetterToUpper(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


User::User() {;}

User::~User() {;}

int User::getID() {
    return id;
}
string User::getName() {
    return name;
}
string User::getSurname() {
    return surname;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}

void User::setID(int identificator) {
    id = identificator;
}
void User::setName(string userName) {
    name = changeFirstLetterToUpper(userName);
}
void User::setSurname(string userSurname) {
    surname = changeFirstLetterToUpper(userSurname);
}
void User::setLogin(string userLogin) {
    login = userLogin;
}
void User::setPassword(string userPassword) {
    password = userPassword;
}
