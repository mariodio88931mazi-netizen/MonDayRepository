#pragma once
#include <iostream>
#include <string>
using namespace std;

double getBalance();
void deposit(double amount);
void withdraw(double amount);
void displayAccountInfo();

class BankAccount
{
private:
    std::string accountHolder; // 口座名義人
    double balance;            // 残高

public:

    //コンストラクタ
    BankAccount(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}

    //残高の取得
    double getBalance() const
    {
        return balance;
    }

    //預け入れ
    void deposit(double amount)
    {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        }
        else {
            cout << "Invalid deposit amount.\n";
        }
    }

    //引き出し
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        }
        else
        {
            cout << "Invalid withdraw amount or insufficient funds.\n";
        }
    }

    //口座情報の表示
    void displayAccountInfo() const
    {
        cout << "Account Holder: " << accountHolder << "\n"
            << "Current Balance: " << balance << "\n";
    }
};