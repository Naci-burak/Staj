#include <iostream>
#include "Account.h"

using namespace std;


Account::Account(int bal, string nm,  string type) : balance{bal}, name{nm} , accountType{type}{
    ++totalAccNum;
    accountNumber = totalAccNum;
}

void Account::withdraw(int amount) {

    if(amount > balance){
        cout << "yeterli bakiye bulunamamaktadir.\n" << "suanki bakiyeniz:" << balance << endl;
    }
    else{
        balance -= amount;
        cout << "Yeni bakiye: " << balance << endl;
    }
}

void Account::deposite(int amount) {
    balance += amount;
    cout << "Yeni bakiye: " << balance << endl;
}

void Account::accountInfo()const {
    cout << "Hesap numarasi: " << accountNumber << " olan musteri " << *name << " " << *accountType <<" hesabinizda " << balance << "tl para bulunmaktadir." << endl;
}

int Account::getAccountNumber()const {
    return accountNumber;
}

int Account::getBalance()const {
    return balance;
}

string Account::getName() {
    return *name;
}

string Account::getAccType() {
    return *accountType;
}



