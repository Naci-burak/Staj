#ifndef CALISMA_5_ACCOUNT_H
#define CALISMA_5_ACCOUNT_H


class Account{

public:
    Account(int, std::string, std::string);
    //~Account();
    void deposite(int);
    void withdraw(int);
    void accountInfo()const;

    //Getter
    std::string getName();
    std::string getAccType();
    int getAccountNumber()const;
    int getBalance()const;


private:

    inline static int totalAccNum = 0;
    int accountNumber;
    int balance;
    std::string name[50];
    std::string accountType[20];

};

// global func
void updateFile(Account& x, int taction);
void choise(Account& Acc);

#endif //CALISMA_5_ACCOUNT_H
