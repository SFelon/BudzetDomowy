#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <windows.h>
#include <vector>

#include "Markup.h"
#include "User.h"

using namespace std;

class UsersFile
{
    string fileName;
    public:
        UsersFile();
        virtual ~UsersFile();

    void loadUsersData(vector <User>& users);
    void saveUsersData(User &newUser);
    void changeUsersPassword(int& idLoggedUser, string& password);
};

#endif // USERSFILE_H
