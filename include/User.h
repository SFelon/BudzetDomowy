#ifndef USER_H
#define USER_H

#include <iostream>
#include <algorithm>

using namespace std;

class User
{
    private:
        int id;
        string name;
        string surname;
        string login;
        string password;

        string changeFirstLetterToUpper(string text);

    public:
        User();
        virtual ~User();

       int getID();
       string getName();
       string getSurname();
       string getLogin();
       string getPassword();

       void setID(int id);
       void setName(string name);
       void setSurname(string surname);
       void setLogin(string login);
       void setPassword(string password);
};

#endif // USER_H
