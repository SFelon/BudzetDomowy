#include "IncomesFile.h"

using namespace std;

IncomesFile::IncomesFile() {
incomesFileName = "incomes.xml";
}

IncomesFile::~IncomesFile() {;}


int IncomesFile::loadLastIdNumber(int& userId) {

int lastIdNumber = 1;
CMarkup xmlFile;
    xmlFile.Load(MCD_T(incomesFileName));
    xmlFile.ResetPos();
    if (!xmlFile.FindElem( "INCOMESFILE" )) {
        return lastIdNumber;
        }
        xmlFile.IntoElem();
        while ( xmlFile.FindElem( "INCOMEDATA" ) ) {
            xmlFile.IntoElem();
            xmlFile.FindElem( "INCOMEID" );
            if (lastIdNumber <= atoi( MCD_2PCSZ(xmlFile.GetData()) ))
            lastIdNumber = atoi( MCD_2PCSZ(xmlFile.GetData()) ) + 1;
            cout << lastIdNumber << " lastId po dodawaniu" << endl;
            xmlFile.OutOfElem();
            }
        return lastIdNumber;
}


void IncomesFile::loadIncomesData() {
    CMarkup xmlFile;

        /*xmlFile.Load(MCD_T(incomesFileName));
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
        }*/
}

void IncomesFile::saveIncomeData(int& incomeId, int& userId, int date, string name, string amount) {
CMarkup xmlFile;
    xmlFile.Load(MCD_T(incomesFileName));
    xmlFile.ResetPos();
    if (!xmlFile.FindElem("INCOMESFILE")) {
        xmlFile.AddElem( "INCOMESFILE" );
        }
        xmlFile.IntoElem();
        xmlFile.AddElem( "INCOMEDATA" );
        xmlFile.IntoElem();
        xmlFile.AddElem( "INCOMEID", incomeId );
        xmlFile.AddElem( "USERID", userId );
        xmlFile.AddElem( "INCOMEDATE", date );
        xmlFile.AddElem( "INCOMENAME", name );
        xmlFile.AddElem( "INCOMEAMOUNT", amount );
        xmlFile.OutOfElem();
    xmlFile.Save(MCD_T(incomesFileName));

    cout<<"Dodano nowy przychod!"<<endl;
    Sleep(1500);
}
