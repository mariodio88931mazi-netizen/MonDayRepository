#include <iostream>
#include <string>
#include"20260829_Problem_.h"
using namespace std;



int main() 
{
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void displayAccountInfo();

    BankAccount account("Alice", 5000.0);

    account.displayAccountInfo();

    account.deposit(1000.0);
    account.withdraw(2000.0);
    account.withdraw(5000.0); // écçÇïsë´Ç≈é∏îs

    account.displayAccountInfo();

    return 0;
}