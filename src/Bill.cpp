#include <sstream>
#include <fstream>
#include "../include/Bill.h"

Bill::Bill() {
    this->creditorName = "none";
    this->totalDebt = 0.00;
    this->monthlyPayment = 0.00;
    this->dueDate = 0;
}

Bill::Bill(std::string name) {
    this->creditorName = name;
}

Bill::Bill(std::string name, double totalDebt, double monthlyPayment, int day) {
    this->creditorName = name;
    this->totalDebt = totalDebt;
    this->monthlyPayment = monthlyPayment;
    this->dueDate = day;
}

void Bill::SetCreditorName(std::string name) {
    this->creditorName = name;
}

void Bill::SetTotalDebt(double totalDebt) {
    this->totalDebt = totalDebt;
}

void Bill::SetMonthlyPayment(double monthlyPayment) {
    this->monthlyPayment = monthlyPayment;
}

void Bill::SetDueDate(int day) {
    this->dueDate = day;
}

std::string Bill::GetCreditorName() const {
    return this->creditorName;
}

double Bill::GetTotalDebt() const {
    return this->totalDebt;
}

double Bill::GetMonthlyPayment() const {
    return this->monthlyPayment;
}

std::string Bill::GetDueDate() const {
    std::ostringstream out;
    out << this->dueDate << "th";
    return out.str();
}

void Bill::Print() const { 
    std::cout << "\nCreditor Name: " << GetCreditorName();
    std::cout << "\nRemaining Balance: " << GetTotalDebt();
    std::cout << "\nMonthly Payment: " << GetMonthlyPayment();
    std::cout << "\nDue Date: " << GetDueDate() << std::endl;
}

void Bill::Print(std::ofstream& outFS) const {
    outFS << GetCreditorName() << ",";
    outFS << GetTotalDebt() << ",";
    outFS << GetMonthlyPayment() << ",";
    outFS << GetDueDate() << std::endl;
}

