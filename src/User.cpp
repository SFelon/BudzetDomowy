#include "User.h"

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


User::User() {
    id = 0;
    name = "";
    surname = "";
    login = "";
    password = "";
}

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

void User::setID(int id) {
    this -> id = id;
}
void User::setName(string name) {
    this -> name = changeFirstLetterToUpper(name);
}
void User::setSurname(string surname) {
    this -> surname = changeFirstLetterToUpper(surname);
}
void User::setLogin(string login) {
    this -> login = login;
}
void User::setPassword(string password) {
    this -> password = password;
}
