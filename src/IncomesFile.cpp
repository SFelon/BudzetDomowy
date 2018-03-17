#include "IncomesFile.h"

using namespace std;


int IncomesFile::getCurrentDate() {
time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
struct tm * ptm = localtime(&tt);
stringstream dateStream;
dateStream << put_time(ptm,"%Y%m");
string dateInString = dateStream.str();
return  stoi(dateInString);
}



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
            if (lastIdNumber <= stoi( MCD_2PCSZ(xmlFile.GetData()) ))
            lastIdNumber = stoi( MCD_2PCSZ(xmlFile.GetData()) ) + 1;
            xmlFile.OutOfElem();
            }
        return lastIdNumber;
}

void IncomesFile::loadCurrentMonthIncomes(int idLoggedUser, vector <Income>& incomes) {
    Income incomeData;
    int intDateToCompare = getCurrentDate();

    CMarkup xmlFile;
        xmlFile.Load(MCD_T(incomesFileName));
        xmlFile.FindElem("INCOMESFILE");
        xmlFile.IntoElem();
            while ( xmlFile.FindElem("INCOMEDATA") ) {
            xmlFile.IntoElem();
            xmlFile.FindElem( "USERID" );
            if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
                incomeData.setUserId(idLoggedUser);
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "INCOMEDATE" );
                string tempDate = (MCD_2PCSZ(xmlFile.GetData()));
                tempDate.erase(remove(tempDate.begin(), tempDate.end(), '-'), tempDate.end());
                if (intDateToCompare == (stoi(tempDate)/100)) {
                incomeData.setDate(xmlFile.GetData());
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "INCOMEID" );
                incomeData.setIncomeId(atoi( MCD_2PCSZ(xmlFile.GetData()) ));
                xmlFile.FindElem( "INCOMENAME" );
                incomeData.setItemName(xmlFile.GetData());
                xmlFile.FindElem( "INCOMEAMOUNT" );
                incomeData.setAmount(xmlFile.GetData());
            incomes.push_back(incomeData);
            }
            }
            xmlFile.OutOfElem();
    }
}


void IncomesFile::loadPreviousMonthIncomes(int idLoggedUser, vector <Income>& incomes) {
    Income incomeData;
    int DateToCompare = getCurrentDate();
    if ((DateToCompare%100) == 1) {
        DateToCompare = (((DateToCompare/100)-1)*100+12);
    } else {
        DateToCompare -= 1;
    }
    CMarkup xmlFile;
        xmlFile.Load(MCD_T(incomesFileName));
        xmlFile.FindElem("INCOMESFILE");
        xmlFile.IntoElem();
            while ( xmlFile.FindElem("INCOMEDATA") ) {
            xmlFile.IntoElem();
            xmlFile.FindElem( "USERID" );
            if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
                incomeData.setUserId(idLoggedUser);
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "INCOMEDATE" );
                string tempDate = (MCD_2PCSZ(xmlFile.GetData()));
                tempDate.erase(remove(tempDate.begin(), tempDate.end(), '-'), tempDate.end());
                if (DateToCompare == (stoi(tempDate)/100)) {
                incomeData.setDate(xmlFile.GetData());
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "INCOMEID" );
                incomeData.setIncomeId(atoi( MCD_2PCSZ(xmlFile.GetData()) ));
                xmlFile.FindElem( "INCOMENAME" );
                incomeData.setItemName(xmlFile.GetData());
                xmlFile.FindElem( "INCOMEAMOUNT" );
                incomeData.setAmount(xmlFile.GetData());
            incomes.push_back(incomeData);
            }
            }
            xmlFile.OutOfElem();
    }
}


void IncomesFile::loadIncomesData(int idLoggedUser, vector <Income>& incomes) {
    Income incomeData;
    CMarkup xmlFile;
        xmlFile.Load(MCD_T(incomesFileName));
        xmlFile.FindElem("INCOMESFILE");
        xmlFile.IntoElem();
            while ( xmlFile.FindElem("INCOMEDATA") ) {
            xmlFile.IntoElem();
            xmlFile.FindElem( "USERID" );
            if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
            incomeData.setUserId(idLoggedUser);
            xmlFile.ResetMainPos();
            xmlFile.FindElem( "INCOMEID" );
                incomeData.setIncomeId(stoi( MCD_2PCSZ(xmlFile.GetData()) ));
            xmlFile.FindElem( "INCOMEDATE" );
                incomeData.setDate(xmlFile.GetData());
            xmlFile.FindElem( "INCOMENAME" );
                incomeData.setItemName(xmlFile.GetData());
            xmlFile.FindElem( "INCOMEAMOUNT" );
                incomeData.setAmount(xmlFile.GetData());
            incomes.push_back(incomeData);
            }
            xmlFile.OutOfElem();
            }
}

void IncomesFile::saveIncomeData(Income& newIncome) {

ostringstream stringToDouble;
stringToDouble << newIncome.getAmount();
string newIncomeAmount = stringToDouble.str();

CMarkup xmlFile;
    xmlFile.Load(MCD_T(incomesFileName));
    xmlFile.ResetPos();
    if (!xmlFile.FindElem("INCOMESFILE")) {
        xmlFile.AddElem( "INCOMESFILE" );
        }
        xmlFile.IntoElem();
        xmlFile.AddElem( "INCOMEDATA" );
        xmlFile.IntoElem();
        xmlFile.AddElem( "INCOMEID", newIncome.getIncomeId() );
        xmlFile.AddElem( "USERID", newIncome.getUserId() );
        xmlFile.AddElem( "INCOMEDATE", newIncome.getDateString() );
        xmlFile.AddElem( "INCOMENAME", newIncome.getItemName() );
        xmlFile.AddElem( "INCOMEAMOUNT", newIncomeAmount );
        xmlFile.OutOfElem();
    xmlFile.Save(MCD_T(incomesFileName));

    cout<<"Dodano nowy przychod!"<<endl;
    Sleep(1500);
}
