#ifndef BILL_H
#define BILL_H

#include <iostream>

class Bill {
    private:
        std::string creditorName;
        double totalDebt;
        double monthlyPayment;
        int dueDate;
    public:
        Bill();
        
        Bill(std::string name, double totalDebt, double monthlyPayment, int day);
        
        void SetCreditorName(std::string name);

        void SetTotalDebt(double totalDebt);

        void SetMonthlyPayment(double monthlyPayment);

        void SetDueDate(int day);

        std::string GetCreditorName() const;

        double GetTotalDebt() const;

        double GetMonthlyPayment() const;

        std::string GetDueDate() const;

        void Print() const;
};

#endif
