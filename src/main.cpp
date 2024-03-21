#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "../include/Bill.h"
#include "../include/LinkedList.h"

using namespace std;

void PrintHeading(string name) {
    cout << left << setw(26) << setfill('*') << "";
    cout << right << name << "'s bills";
    cout << setw(26) << setfill('*') << "" << endl;
}

LinkedList importCSV() {
    ifstream inFS;
    string name;
    LinkedList billList;

    cout << "Input a file name: " << endl;
    cin.ignore();
    getline(cin, name);
    inFS.open(name);
    
    if (!inFS.is_open()) {
        cout << "Error opening " << name << endl;
    } else {
        string line;

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
                LinkedListNode* newNode = new LinkedListNode(bill);
                billList.Append(newNode);
            }
        }
        inFS.close();
    }

    return billList;
}

Bill* createBillFromUserInput() {
    string creditorName;
    double totalDue;
    double monthlyPayment;
    int dueDate;
    
    cin.ignore();
    cout << "Creditor Name: ";
    getline(cin, creditorName);

    cout << "Total Balance: ";
    cin >> totalDue;

    cout << "Monthly Payment: ";
    cin >> monthlyPayment;

    cout << "Due Date (day of the month): ";
    cin >> dueDate;

    return new Bill(creditorName, totalDue, monthlyPayment, dueDate);
}

int main() {
    string userName;
    char userSelect = -1;
    ofstream outFS("../export/export.csv");
    LinkedList billsDue;

    cout << "Enter your first name: ";
    cin >> userName;

    // Checks to see if export.csv has been created and reads each value into the billsDue list
    billsDue = importCSV();

    PrintHeading(userName);

    // Populate linked list of user-inputted bills
    while (userSelect != 'q' && userSelect != 'Q') {
        Bill* tempBill = createBillFromUserInput();
        LinkedListNode* current = new LinkedListNode(tempBill);
        billsDue.Append(current);
        cout << "Press any ascii value to add a bill, q to quit: ";
        cin >> userSelect;
    }

    // Print out each value
    PrintHeading(userName);
    billsDue.DisplayList();

    // Write the values to an external csv document.
    if (!outFS.is_open()) {
        cout << "Error opening export.csv" << std::endl;
        return 1;
    }
    billsDue.PrintList(outFS);    
    outFS.close();

    return 0;
}
