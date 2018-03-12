#include "UsersFile.h"

using namespace std;

UsersFile::UsersFile() {
fileName = "users.xml";
}

UsersFile::~UsersFile() {;}

void UsersFile::loadUsersData(vector <User>& users) {
    User userToLoad;
    CMarkup xmlFile;

        xmlFile.Load(MCD_T(fileName));
        xmlFile.FindElem("USERFILE");
        xmlFile.IntoElem();
            while ( xmlFile.FindElem("USERDATA") ) {
            xmlFile.IntoElem();
            xmlFile.FindElem( "USERID" );
                userToLoad.setID(atoi( MCD_2PCSZ(xmlFile.GetData()) ));
            xmlFile.FindElem( "NAME" );
                userToLoad.setName(xmlFile.GetData());
            xmlFile.FindElem( "SURNAME" );
                userToLoad.setSurname(xmlFile.GetData());
            xmlFile.FindElem( "LOGIN" );
                userToLoad.setLogin(xmlFile.GetData());
            xmlFile.FindElem( "PASSWORD" );
                userToLoad.setPassword(xmlFile.GetData());
            xmlFile.OutOfElem();
            users.push_back(userToLoad);
        }
}

void UsersFile::saveUsersData(User& newUser) {
CMarkup xmlFile;
    xmlFile.Load(MCD_T(fileName));
    xmlFile.ResetPos();
    if (!xmlFile.FindElem("USERFILE")) {
        xmlFile.AddElem( "USERFILE" );
        }
        xmlFile.IntoElem();
        xmlFile.AddElem( "USERDATA" );
        xmlFile.IntoElem();
        xmlFile.AddElem( "USERID", newUser.getID() );
        xmlFile.AddElem( "NAME", newUser.getName() );
        xmlFile.AddElem( "SURNAME", newUser.getSurname() );
        xmlFile.AddElem( "LOGIN", newUser.getLogin() );
        xmlFile.AddElem( "PASSWORD", newUser.getPassword() );
        xmlFile.OutOfElem();
    xmlFile.Save(MCD_T(fileName));
    cout<<"Konto zalozone"<<endl;
    Sleep(1000);
}

void UsersFile::changeUsersPassword(int& idLoggedUser, string& password) {
    CMarkup xmlFile;
    if (xmlFile.Load(MCD_T(fileName))) {
        xmlFile.ResetPos();
        xmlFile.FindElem("USERFILE");
        xmlFile.IntoElem();
        while ( xmlFile.FindElem("USERDATA") ) {
            xmlFile.FindChildElem( "USERID" );
            if ( atoi( MCD_2PCSZ(xmlFile.GetChildData()) ) == idLoggedUser ) {
                xmlFile.FindChildElem( "PASSWORD" );
                xmlFile.SetChildData( password );
                break;
            }
        }
        xmlFile.Save(MCD_T(fileName));
        cout<<"Haslo zostalo zmienione";
        Sleep(1000);
    } else {
    cout << "Nie mozna otworzyc pliku z danymi uzytkownikow!";
    Sleep(2000);
    exit(0);
}
}
