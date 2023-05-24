#include <iostream>

using namespace std;

void funcVal(int x){        // call by value

    ++x;
    cout << "CBV x in degeri:" << x << endl;
}

void funcRef(int& x){      // pass by reference

    ++x;
    cout << "PBR x in degeri:" << x << endl;
}

int gVal = 15;

int* func(){

    return &gVal;
}

int& funcR(int &x){

    ++x;
    return x;
}


int main() {

    int val{10};
    int iVal{5};

    int a = funcR(iVal);
    int b = *func();

    cout << "a nin degeri:" << a << endl;
    cout << "b nin degeri:" << b << endl;


    cout << "val degeri:" << val << endl;
    funcVal(val);
    cout << "val degeri:" << val << endl;
    funcRef(val);
    cout << "val degeri:" << val << endl;

    int* const ptr = &val;
    int& r = val;

    //double& dr = x;       //tür dönüşümü gerekli

    cout << "ptr degeri:" << *ptr << endl;
    cout << "r nin degeri:" << r << endl;

    // Kısım 2

    int xVal = 5;
    int* ptr1 {&xVal};
    int& ref {*ptr1};
    ++ref;
    cout << "xVal degeri:" << xVal << endl;


    //Kısım 3

    int i = 20;
    const int& r1 = i;

    cout << "r1 : " << r1 << endl;

    double j = 10.5;
    const int &r2 = j;      // const geçici değişken oluşturur tür dönüşümü sıkıntı değil. narrowing conversion!

    cout << "r2 : " << r2 << endl;

    return 0;
}
