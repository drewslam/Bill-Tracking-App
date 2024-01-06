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
    ifstream inFS("export/export.csv");
    LinkedList billList;

    if (inFS.is_open()) {
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
    

    cout << "Creditor Name: ";
    cin.ignore();
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
    ofstream outFS;
    LinkedList billsDue;

    cout << "Enter your first name: ";
    cin >> userName;
    
    PrintHeading(userName);

    // Checks to see if export.csv has been created and reads each value into the billsDue list
    billsDue = importCSV();
    
    // Populate linked list of user-inputted bills
    while (userSelect != 'q' && userSelect != 'Q') {
        Bill* tempBill = createBillFromUserInput();
        LinkedListNode* current = new LinkedListNode(tempBill);
        billsDue.Append(current);
        // current->GetData()->Print();
        cout << "Press any ascii value to add a bill, q to quit: ";
        cin >> userSelect;
    }

    // Print out each value
    PrintHeading(userName);
    billsDue.Display();

    // Write the values to an external csv document.
    outFS.open("../export/export.csv");

    return 0;
}
