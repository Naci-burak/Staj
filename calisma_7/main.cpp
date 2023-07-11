#include "Time.h"
#include <iostream>

using namespace std;

/*
int main(){

Time t5;
Time t6(235345);

cout << t5;
cout << t6;
Time mt(1,3,5,50);
return 0;


Time t1(5,23,4,35);
Time t2(5,23,4,35);
//cout << mt;
//cin >> mt;
cout << t1;
cout << t2;

Time b = t1 + t2;

cout << b;
cout << t1;
cout << t2;


Time a = t1 += t2;

cout << a;
cout << t1;
cout << t2;
}
*/

int main() {

    Time t1, t2, t3(123456), t4(987654321);

    cout << "t1 = " << t1 << '\n';
    cout << "t2 = " << t2 << '\n';
    cout << "t3 = " << t3 << '\n';
    cout << "t4 = " << t4 << '\n';

    cout << "Enter t1): ";
    cin >> t1;
    cout << "Enter t2): ";
    cin >> t2;

    cout << t1 << " + " << t2 << " = " << t1 + t2 << '\n';
    cout << t1 << " - " << t2 << " = " << t1 - t2 << "\n\n";

    if (t1 < t2) cout << t1 << " < " << t2 << " is TRUE\n";
    if (t1 > t2) cout << t1 << " > " << t2 << " is TRUE\n";
    if (t1 <= t2) cout << t1 << " <= " << t2 << " is TRUE\n";
    if (t1 >= t2) cout << t1 << " >= " << t2 << " is TRUE\n";
    if (t1 == t2) cout << t1 << " == " << t2 << " is TRUE\n";
    if (t1 != t2) cout << t1 << " != " << t2 << " is TRUE\n\n";

    cout << t1 << " + 654321 = " << t1 + 654321 << '\n';
    cout << t2 << " + 15263748 = " << t2 + 15263748 << '\n';

    return 0;
}
