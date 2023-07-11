#pragma once
#include <iostream>

class Time{
public:

    Time();
    Time(int ts);   //conversion ctor
    Time(int td, int th, int tm, int ts);

    Time& operator++();         //prefix
    Time operator++(int);       //postfix
    Time& operator--();
    Time operator--(int);

    Time& operator+=(Time&);
    Time& operator-=(Time&);
    Time operator+(Time&);
    Time& operator+(int);       //int sum
    Time operator-(Time&);
    Time operator*(int);

    //compare
    friend bool operator==(const Time &t1, const Time &t2);
    friend bool operator>=(const Time &t1, const Time &t2);
    friend bool operator<=(const Time &t1, const Time &t2);
    friend bool operator!=(const Time &t1, const Time &t2);
    friend bool operator<(const Time &t1, const Time &t2);
    friend bool operator>(const Time &t1, const Time &t2);

    //stream
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    friend std::istream& operator>>(std::istream& is, Time& t);


private:
    int day, hour, minute, second;

};

