#include <iostream>
#include <windows.h>

#include "UsersFile.h"
#include "Markup.h"

using namespace std;

UsersFile::UsersFile() {;}

UsersFile::~UsersFile() {;}

void UsersFile::loadUsersData(vector <User>& users) {
    User userToLoad;
    CMarkup xml;

    xml.Load(MCD_T("Users.xml"));
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("USERDATA") ) {
        xml.IntoElem();
        xml.FindElem( "ID" );
            userToLoad.setID(atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem( "NAME" );
            userToLoad.setName(xml.GetData());
        xml.FindElem( "SURNAME" );
            userToLoad.setSurname(xml.GetData());
        xml.FindElem( "LOGIN" );
            userToLoad.setLogin(xml.GetData());
        xml.FindElem( "PASSWORD" );
            userToLoad.setPassword(xml.GetData());
        xml.OutOfElem();
        users.push_back(userToLoad);
    }
}

void UsersFile::saveUsersData(User& newUser) {
    CMarkup xml;
    xml.Load(MCD_T("Users.xml"));
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
        xml.AddElem( "USERDATA" );
        xml.IntoElem();
        xml.AddElem( "ID", newUser.getID() );
        xml.AddElem( "NAME", newUser.getName() );
        xml.AddElem( "SURNAME", newUser.getSurname() );
        xml.AddElem( "LOGIN", newUser.getLogin() );
        xml.AddElem( "PASSWORD", newUser.getPassword() );
        xml.OutOfElem();
    xml.Save(MCD_T("Users.xml"));
}

void UsersFile::changeUsersPassword(int& idLoggedUser, string& password) {
    CMarkup xml;
    xml.Load(MCD_T("Users.xml"));
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("USERDATA") ) {
        xml.FindChildElem( "ID" );
        if ( atoi( MCD_2PCSZ(xml.GetChildData()) ) == idLoggedUser ) {
            xml.FindChildElem( "PASSWORD" );
            xml.SetChildData( password );
            break;
        }
    }
    xml.Save(MCD_T("Users.xml"));
    cout<<"Haslo zostalo zmienione";
    Sleep(1000);
}
