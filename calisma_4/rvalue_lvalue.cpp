#include <iostream>

using namespace std;

/*
    void func (int r){
    cout << "func. r degeri :"<< r << endl;
}
 */
void func (int &r){
    cout << "sol taraf referansi. r degeri:" << r << endl;
}
void func(int &&r){
    cout << "sag taraf referansi. r degeri:" << r << endl;
}


int sum (int k, int m){
    return k+m;
}

int main() {

    int a = 5;

    func(10);
    func(a);

    int x = 5;
    int y = 10;
    int result = sum(x,y);
    cout << "result :" << result << endl;
/*
    x = 2;
    y = 3;
    int &result1 = sum(x,y);                  // syntax error
    cout << "result :" << result1 << endl;
*/
    x = 4;
    y = 8;
    const int &result2 = sum(x,y);      //  const yaptığımızda
    cout << "result :" << result2 << endl;


    x = 1;
    y = 2;
    int &&result3 = sum(x,y);
    cout << "result :" << result3 << endl;     //&&

    x = 4;
    y = 5;
    const int &&result4 = sum(x,y);      //const type&&
    cout << "result :" << result4 << endl;

    return 0;
}
