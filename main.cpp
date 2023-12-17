#include <iostream>
#include <iomanip>
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

int main() {
    string userName;
    string creditorName;
    double totalDue;
    double monthlyPayment;
    int dueDate;
    int numBills = 0;
    char userSelect = -1;
    Bill** billsDue = new Bill*;

    cout << "Enter your first name: ";
    cin >> userName;
    
    PrintHeading(userName);

    // Populate array of user-inputted bills
    while (userSelect != 'q' && userSelect != 'Q') {
        Bill* hellaBill = new Bill;
        numBills++;

        cout << "Creditor Name: ";
        cin.ignore();
        getline(cin, creditorName);
        hellaBill->SetCreditorName(creditorName);

        cout << "Total Balance: ";
        cin >> totalDue;
        hellaBill->SetTotalDebt(totalDue);

        cout << "Monthly Payment: ";
        cin >> monthlyPayment;
        hellaBill->SetMonthlyPayment(monthlyPayment);

        cout << "Due Date (day of the month): ";
        cin >> dueDate;
        hellaBill->SetDueDate(dueDate);
        
        billsDue = Extend(billsDue, numBills, 1);
        billsDue[numBills - 1] = hellaBill;

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

    delete[] billsDue;

    return 0;
}
