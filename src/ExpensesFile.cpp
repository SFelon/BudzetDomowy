#include "ExpensesFile.h"

using namespace std;


int ExpensesFile::getCurrentYearMonth() {
    time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
    struct tm * ptm = localtime(&tt);
    stringstream dateStream;
    dateStream << put_time(ptm,"%Y%m");
    return  stoi(dateStream.str());
}

string ExpensesFile::doubleToString(double number) {
    stringstream sstream;
    sstream << fixed << setprecision(2) << number;
    return sstream.str();
}


ExpensesFile::ExpensesFile() {
expensesFileName = "expenses.xml";
}

ExpensesFile::~ExpensesFile() {;}


int ExpensesFile::loadLastIdNumber(int& userId) {

    int lastIdNumber = 1;
    CMarkup xmlFile;
    xmlFile.Load(MCD_T(expensesFileName));
    xmlFile.ResetPos();
    if (!xmlFile.FindElem( "EXPENSESFILE" )) {
        return lastIdNumber;
    }
    xmlFile.IntoElem();
    while ( xmlFile.FindElem( "EXPENSEDATA" ) ) {
        xmlFile.IntoElem();
        xmlFile.FindElem( "EXPENSEID" );
        if (lastIdNumber <= stoi( MCD_2PCSZ(xmlFile.GetData()) ))
            lastIdNumber = stoi( MCD_2PCSZ(xmlFile.GetData()) ) + 1;
        xmlFile.OutOfElem();
    }
    return lastIdNumber;
}

void ExpensesFile::loadCurrentMonthExpenses(int idLoggedUser, vector <Expense>& expenses) {
    Expense expenseData;
    int intDateToCompare = getCurrentYearMonth();

    CMarkup xmlFile;
    xmlFile.Load(MCD_T(expensesFileName));
    xmlFile.FindElem("EXPENSESFILE");
    xmlFile.IntoElem();
    while ( xmlFile.FindElem("EXPENSEDATA") ) {
        xmlFile.IntoElem();
        xmlFile.FindElem( "USERID" );
        if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
            expenseData.setUserId(idLoggedUser);
            xmlFile.ResetMainPos();
            xmlFile.FindElem( "EXPENSEDATE" );
            string tempDate = (MCD_2PCSZ(xmlFile.GetData()));
            tempDate.erase(remove(tempDate.begin(), tempDate.end(), '-'), tempDate.end());
            if (intDateToCompare == (stoi(tempDate)/100)) {
                expenseData.setDate(xmlFile.GetData());
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "EXPENSEID" );
                expenseData.setExpenseId(atoi( MCD_2PCSZ(xmlFile.GetData()) ));
                xmlFile.FindElem( "EXPENSENAME" );
                expenseData.setItemName(xmlFile.GetData());
                xmlFile.FindElem( "EXPENSEAMOUNT" );
                expenseData.setAmount(xmlFile.GetData());
                expenses.push_back(expenseData);
            }
        }
        xmlFile.OutOfElem();
    }
}


void ExpensesFile::loadPreviousMonthExpenses(int idLoggedUser, vector <Expense>& expenses) {
    Expense expenseData;

    int DateToCompare = getCurrentYearMonth();
    if ((DateToCompare%100) == 1) {
        DateToCompare = (((DateToCompare/100)-1)*100+12);
    } else {
        DateToCompare -= 1;
    }

    CMarkup xmlFile;
    xmlFile.Load(MCD_T(expensesFileName));
    xmlFile.FindElem("EXPENSESFILE");
    xmlFile.IntoElem();
    while ( xmlFile.FindElem("EXPENSEDATA") ) {
        xmlFile.IntoElem();
        xmlFile.FindElem( "USERID" );
        if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
            expenseData.setUserId(idLoggedUser);
            xmlFile.ResetMainPos();
            xmlFile.FindElem( "EXPENSEDATE" );
            string tempDate = (MCD_2PCSZ(xmlFile.GetData()));
            tempDate.erase(remove(tempDate.begin(), tempDate.end(), '-'), tempDate.end());
            if (DateToCompare == (stoi(tempDate)/100)) {
                expenseData.setDate(xmlFile.GetData());
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "EXPENSEID" );
                expenseData.setExpenseId(atoi( MCD_2PCSZ(xmlFile.GetData()) ));
                xmlFile.FindElem( "EXPENSENAME" );
                expenseData.setItemName(xmlFile.GetData());
                xmlFile.FindElem( "EXPENSEAMOUNT" );
                expenseData.setAmount(xmlFile.GetData());
                expenses.push_back(expenseData);
            }
        }
        xmlFile.OutOfElem();
    }
}

void ExpensesFile::loadSelectedPeriodExpenses(int idLoggedUser, vector <Expense>& expenses,
                                            int startingDate, int endDate) {
    Expense expenseData;
    CMarkup xmlFile;
    xmlFile.Load(MCD_T(expensesFileName));
    xmlFile.FindElem("EXPENSESFILE");
    xmlFile.IntoElem();
    while ( xmlFile.FindElem("EXPENSEDATA") ) {
        xmlFile.IntoElem();
        xmlFile.FindElem( "USERID" );
        if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
            expenseData.setUserId(idLoggedUser);
            xmlFile.ResetMainPos();
            xmlFile.FindElem( "EXPENSEDATE" );
            string tempDate = (MCD_2PCSZ(xmlFile.GetData()));
            tempDate.erase(remove(tempDate.begin(), tempDate.end(), '-'), tempDate.end());
            if ( (stoi(tempDate) >= startingDate) && (stoi(tempDate) <= endDate ) ) {
                expenseData.setDate(xmlFile.GetData());
                xmlFile.ResetMainPos();
                xmlFile.FindElem( "EXPENSEID" );
                expenseData.setExpenseId(atoi( MCD_2PCSZ(xmlFile.GetData()) ));
                xmlFile.FindElem( "EXPENSENAME" );
                expenseData.setItemName(xmlFile.GetData());
                xmlFile.FindElem( "EXPENSEAMOUNT" );
                expenseData.setAmount(xmlFile.GetData());
                expenses.push_back(expenseData);
            }
        }
        xmlFile.OutOfElem();
    }
}

void ExpensesFile::loadExpensesData(int idLoggedUser, vector <Expense>& expenses) {
    Expense expenseData;
    CMarkup xmlFile;
    xmlFile.Load(MCD_T(expensesFileName));
    xmlFile.FindElem("EXPENSESFILE");
    xmlFile.IntoElem();
    while ( xmlFile.FindElem("EXPENSEDATA") ) {
        xmlFile.IntoElem();
        xmlFile.FindElem( "USERID" );
        if (idLoggedUser == (stoi( MCD_2PCSZ(xmlFile.GetData()) ))) {
            expenseData.setUserId(idLoggedUser);
            xmlFile.ResetMainPos();
            xmlFile.FindElem( "EXPENSEID" );
            expenseData.setExpenseId(stoi( MCD_2PCSZ(xmlFile.GetData()) ));
            xmlFile.FindElem( "EXPENSEDATE" );
            expenseData.setDate(xmlFile.GetData());
            xmlFile.FindElem( "EXPENSENAME" );
            expenseData.setItemName(xmlFile.GetData());
            xmlFile.FindElem( "EXPENSEAMOUNT" );
            expenseData.setAmount(xmlFile.GetData());
            expenses.push_back(expenseData);
        }
        xmlFile.OutOfElem();
    }
}

void ExpensesFile::saveExpenseData(Expense& newExpense) {
    CMarkup xmlFile;
    xmlFile.Load(MCD_T(expensesFileName));
    xmlFile.ResetPos();
    if (!xmlFile.FindElem("EXPENSESFILE")) {
        xmlFile.AddElem( "EXPENSESFILE" );
    }
    xmlFile.IntoElem();
    xmlFile.AddElem( "EXPENSEDATA" );
    xmlFile.IntoElem();
    xmlFile.AddElem( "EXPENSEID", newExpense.getExpenseId() );
    xmlFile.AddElem( "USERID", newExpense.getUserId() );
    xmlFile.AddElem( "EXPENSEDATE", newExpense.getDateString() );
    xmlFile.AddElem( "EXPENSENAME", newExpense.getItemName() );
    xmlFile.AddElem( "EXPENSEAMOUNT", doubleToString(newExpense.getAmount()) );
    xmlFile.OutOfElem();
    xmlFile.Save(MCD_T(expensesFileName));

    cout<<"Dodano nowy wydatek!"<<endl;
    Sleep(1500);
}
