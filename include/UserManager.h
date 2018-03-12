#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <windows.h>
#include <cstdlib>

#include "UsersFile.h"
#include "Markup.h"

using namespace std;

class UserManager
{
    vector <User> users;
    int idLoggedUser = 0;

    int getNewUserID();

    public:
        UserManager();
        virtual ~UserManager();

    int getidLoggedUser();
    void setidLoggedUser(int idLoggedUser);

    vector <User>& getUsersData();

    void registerNewUser();
    void loginUser();
    void changePassword();
};

#endif // USERMANAGER_H
