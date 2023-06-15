#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"

using namespace std;


void choise(Account& Acc) {

    int amount, accNo, taction;     // para miktari, hesap numarasi, işlem türü

    string nm;           // isim
    string accType;      // hesap türü

    cout << "\n\n\t" << "MENU" << "\n\n" << "yapilacak islemi seciniz:\n" << "1.hesap acma\n" << "2.para cekme\n" << "3.para yatirma\n" << "4.hesap kapatma\n" << "5. hesap bilgilerini goster\n";
    cin >> taction;


    switch (taction) {

        case 1:{

            cout << "hesap acmak icin gerekli bilgileri giriniz.\n";
            cout << "yatirilacak para miktari:";
            cin >> amount;
            cout << "Acilacak hesap turu:";
            cin >> accType;
            cout << "isim bilgileri:";
            cin >> nm;
            Account a(amount, nm, accType);
            a.accountInfo();
            updateFile(a,taction);
        }
            break;

        case 2:
            cout << "Cekilecek para miktarini giriniz:";
            cin >> amount;
            Acc.withdraw(amount);
            updateFile(Acc,taction);
            break;
        case 3:
            cout << "Yatirilacak para miktarini giriniz:";
            cin >> amount;
            Acc.deposite(amount);
            updateFile(Acc,taction);
            break;
        case 4:
            cout << "silmek istediginiz hesabinizin numarasini giriniz:";
            cin >> accNo;
            updateFile(Acc,taction);
            delete &Acc;
            break;
        case 5:
            Acc.accountInfo();
            break;
        default:
            cout << "secim gecersiz.";
            break;

    }

}

void updateFile(Account& x, int taction) {


    int accNum = x.getAccountNumber();



    if(taction == 1){           // acma

        fstream readFile;
        ofstream writeFile;

        readFile.open("accounts.txt" );

        vector<string> lines;
        string line;

        while(getline(readFile, line)){
            lines.push_back(line);
        }

        readFile.close();

        writeFile.open("accounts.txt");
        accNum--;

        for (int i = 0 ; i <= lines.size(); i++){

            if( i != accNum)
                writeFile << lines[i] << endl;
            else
                writeFile << x.getAccountNumber() << "\t" << x.getName() << "\t" << x.getAccType() << "\t" << x.getBalance() << endl;
        }

        writeFile.close();


    }else if (taction == 2){    // cekme

        fstream readFile;
        ofstream writeFile;

        readFile.open("accounts.txt" );

        vector<string> lines;
        string line;

        while(getline(readFile, line)){
            lines.push_back(line);
        }

        readFile.close();

        writeFile.open("accounts.txt");
        accNum--;

        for (int i = 0 ; i < lines.size(); i++){

            if( i != accNum)
                writeFile << lines[i] << endl;
            else
                writeFile << x.getAccountNumber() << "\t" << x.getName() << "\t" << x.getAccType() << "\t" << x.getBalance() << endl;
        }

        writeFile.close();

    }else if (taction == 3){    // yatirma

        fstream readFile;
        ofstream writeFile;

        readFile.open("accounts.txt");

        vector<string> lines;
        string line;

        while(getline(readFile, line)){
            lines.push_back(line);
        }

        readFile.close();

        writeFile.open("accounts.txt" );
        accNum--;

        for (int i = 0 ; i < lines.size(); i++){

            if( i != accNum)
                writeFile << lines[i] << endl;
            else
                writeFile << x.getAccountNumber() << "\t" << x.getName() << "\t" << x.getAccType() << "\t" << x.getBalance() << endl;
        }

        writeFile.close();

    }else if (taction == 4) {    // kapama

        fstream readFile;
        ofstream writeFile;

        readFile.open("accounts.txt");

        vector<string> lines;
        string line;

        while(getline(readFile, line)){
            lines.push_back(line);
        }

        readFile.close();

        writeFile.open("accounts.txt");
        accNum--;

        for (int i = 0 ; i < lines.size(); i++) {

            if (i != accNum)
                writeFile << lines[i] << endl;
            else
                writeFile << x.getAccountNumber() << endl;
        }

        writeFile.close();

    }

}


int main() {


    //oluşturulan hesap bilgileri
    auto a1 = new Account(4000, "Naci" , "salary");
    updateFile(*a1,1);
    auto a2 = new Account(1000, "Fırat", "current");
    updateFile(*a2,1);
    auto a3 = new Account(100, "Ecem" , "saving");
    updateFile(*a3,1);
    auto a4 = new Account(4500, "Beyza" , "saving");
    updateFile(*a4,1);


    choise(*a2);


    a1->accountInfo();
    a3->accountInfo();
    a4->accountInfo();


    return 0;
}
