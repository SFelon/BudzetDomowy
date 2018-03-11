#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "UsersFile.h"

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
    void setidLoggedUser(int id);

    vector <User>& getUsersData();

    void registerNewUser();
    void loginUser();
    void changePassword();
};

#endif // USERMANAGER_H
