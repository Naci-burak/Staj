#include <iostream>

int func(int);
const int* func1(int);
int& func3 (int);

int main() {

    //auto denemeleri

    int k = 10;
    int& r = k;
    int* ptr = &k;

    auto a1 = r;      // int
    auto a2 = *ptr;   //int

    const int& r1 = k;
    auto a3 = r1;    //int

    auto a4 = func;  //int(*) int

    int arr[10];

    auto a5 = arr;        //int*
    auto& a6 = arr;    //int& [10]

    auto& a7= "naci";   //const char&[5]
    const auto & a8 = k;    //const int&

    auto a9 = &k;               //int*
    auto* a10 = &k;             //int*

    // decltype denemeleri

    int x = 10;
    int y = 20;
    const int z = 5;
    int* ptr1 = &x;
    int** ptr2 = &ptr1;
    int& ref = y;

    decltype(x+5)t1;              //int
    decltype(*ptr1) t2 = y;     //int &
    decltype(**ptr2) t3= y;     //int &
    decltype(z) t4 = y;      //const int

    decltype(x) t5 = y;         //int
    decltype((x)) t6=y;       //int &
    decltype(ref)  t7 = y;      //int &

    decltype(++x) t8 = y;     //int &
    decltype(x++) t9=y;         //int
    decltype(ptr2) t10;        //int**

    return 0;
}
