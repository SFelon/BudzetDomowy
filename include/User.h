#ifndef USER_H
#define USER_H
#include <iostream>

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

       void setID(int identificator);
       void setName(string userName);
       void setSurname(string userSurname);
       void setLogin(string userLogin);
       void setPassword(string userPassword);
};

#endif // USER_H
