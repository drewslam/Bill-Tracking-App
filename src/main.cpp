#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "Bill.h"

using namespace std;

void PrintHeading(string name) {
    cout << left << setw(26) << setfill('*') << "";
    cout << right << name << "'s bills";
    cout << setw(26) << setfill('*') << "" << endl;
}

Bill** Extend(Bill** bills, int numBills, int append) {
    Bill** newArr = new Bill*[numBills + append];
    
    for (int i = 0; i < numBills; i++) {
        newArr[i] = bills[i];
    }

    return newArr;
}

Bill** importCSV(Bill** bills, int& count) {
    ifstream inFS("export/export.csv");
    Bill** newArr = nullptr;

    if (inFS.is_open()) {
        string line;
        while (getline(inFS, line)) {
            count++;
        }
        inFS.clear();
        inFS.seekg(0, ios::beg);

        newArr = new Bill*[count];
        int index = 0;

        while (getline(inFS, line)) {
            istringstream inSS(line);
            string name, debt, payment, date;
            
            if (getline(inSS, name, ',') &&
                getline(inSS, debt, ',') &&
                getline(inSS, payment, ',') &&
                getline(inSS, date, ',')) {
                
                double debtVal = stod(debt);
                double paymentVal = stod(payment);
                int dateVal = stoi(date);

                Bill* bill = new Bill(name, debtVal, paymentVal, dateVal);
                newArr[index++] = bill;
            }
        }
    }

    return newArr;
}

int main() {
    string userName;
    string creditorName;
    double totalDue;
    double monthlyPayment;
    int dueDate;
    int numBills = 0;
    char userSelect = -1;
    ofstream outFS;
    Bill** billsDue = new Bill*;

    cout << "Enter your first name: ";
    cin >> userName;
    
    PrintHeading(userName);

    // Checks to see if export.csv has been created and reads each value into the billsDue array
    billsDue = importCSV(billsDue, numBills);
    
    // Populate array of user-inputted bills
    while (userSelect != 'q' && userSelect != 'Q') {
        Bill* tempBill = new Bill;
        numBills++;

        cout << "Creditor Name: ";
        cin.ignore();
        getline(cin, creditorName);
        tempBill->SetCreditorName(creditorName);

        cout << "Total Balance: ";
        cin >> totalDue;
        tempBill->SetTotalDebt(totalDue);

        cout << "Monthly Payment: ";
        cin >> monthlyPayment;
        tempBill->SetMonthlyPayment(monthlyPayment);

        cout << "Due Date (day of the month): ";
        cin >> dueDate;
        tempBill->SetDueDate(dueDate);
        
        billsDue = Extend(billsDue, numBills, 1);
        billsDue[numBills - 1] = tempBill;

        cout << "Press any ascii value to add a bill, q to quit: ";
        cin >> userSelect;
    }

    // Print out each value
    PrintHeading(userName);
    for (int i = 0; i < numBills; i++) {
        cout << setw(26 + userName.size() + 34) << setfill('-') << "" << endl;
        billsDue[i]->Print();
        cout << setw(26 + userName.size() + 34) << setfill('-') << "" << endl;
    }

    // Write the values to an external csv document.
    outFS.open("../export/export.csv");
    for (int i = 0; i < numBills; i++) {
        outFS << billsDue[i]->GetCreditorName() << ",";
        outFS << billsDue[i]->GetTotalDebt() << ",";
        outFS << billsDue[i]->GetMonthlyPayment() << ",";
        outFS << billsDue[i]->GetDueDate() << "," << endl;
    }
    outFS.close();

    for (int i = 0; i < numBills; i++) {
        delete billsDue[i];
    }
    delete billsDue;

    return 0;
}
