#include <iostream>
#include "Time.h"

using namespace std;


ostream& operator<<(ostream& os, const Time& t){
    return os << t.day << " ~ " << t.hour << ": " << t.minute << ": " << t.second << "\n";
}

istream& operator>>(istream& is, Time& t){

    cout << "Gun, saat, dakika ve saniyeyi sirasiyla Giriniz:";
    is >> t.day >> t.hour >> t.minute >> t.second;

    if(t.day < 0 || t.hour < 0 || t.minute < 0 || t.second < 0){
        t.day = 0;
        t.hour = 0;
        t.minute = 0;
        t.second = 0;
    }
    else{
        Time t1(t.day,t.hour,t.minute,t.second);
        t.day = t1.day;
        t.hour = t1.hour;
        t.minute = t1.minute;
        t.second = t1.second;
    }

    return is;

}

Time::Time() : day{0}, hour{0}, minute{0}, second{0} { }

Time::Time(int ts) {

    if(ts >= 0){
        second = ts % 60;
        minute = (ts/60) % 60;
        hour = ((ts/60)/60) % 24;
        day = ((ts/60)/60) / 24;
    }
    else{
        second = 0;
        minute = 0;
        hour = 0;
        day = 0;
    }
}

Time::Time(int td, int th, int tm, int ts) {

    if(td >= 0){
        if(th >= 0){
            if(tm >=0){
                if(ts >=0){
                    second = ts % 60;
                }
                else{
                    second = 0;
                }
                minute = (tm+ts/60)%60;
            }
            else{
                minute = 0;
            }
            hour = (th+(tm+ts/60)/60) %24;
        }
        else{
            hour = 0;
        }
        day = td+(th+(tm+ts/60)/60)/24;
    }
    else{
        day = 0;
    }
}

Time& Time::operator++() {
    ++second;
    if(second >= 60 ){
        second = second % 60;
        ++minute;
    }
    if(minute >= 60){
        minute = minute % 60;
        ++hour;
    }
    if(hour >= 24){
        hour = hour % 24;
        ++day;
    }
    return *this;
}

Time& Time::operator--() {

    if(second != 0 || minute != 0 || hour != 0 || day != 0) {
        if (second - 1 < 0) {
            second += 60;
            --second;
            --minute;

            if (minute < 0) {
                minute += 60;
                --hour;

                if (hour < 0) {
                    hour += 24;
                    --day;

                    if (day < 0)
                        day = 0;
                }
            }
        }
        else
            --second;
    }

    return *this;
}

Time Time::operator++(int) {
    Time temp{*this};
    operator++();
    return temp;
}

Time Time::operator--(int) {
    Time temp{*this};
    operator--();
    return temp;
}

Time& Time::operator+=(Time & t) {

    second += t.second;
    if(second >= 60 ){
        second = second % 60;
        ++minute;
    }
    minute += t.minute;
    if(minute >= 60){
        minute = minute % 60;
        ++hour;
    }
    hour += t.hour;
    if(hour >= 24){
        hour = hour % 24;
        ++day;
    }
    day += t.day;
    return *this;
}

Time Time::operator+(Time & t) {
    Time temp{*this};
    temp+=t;
    return temp;
}

Time &Time::operator+(int ts) {

    if(ts >= 0){
        Time temp(ts);
        operator+=(temp);
    }
    return *this;
}

Time& Time::operator-=(Time & t){       // çıkarma yapı değiş

    if(*this < t){
        if(second-t.second < 0){
            second+=60;
            second-=t.second;
            --minute;
        }
        else{
            second-=t.second;
        }
        if(minute-t.minute < 0){
            minute+=60;
            minute-=t.minute;
            --hour;
        }
        else{
            minute-=t.minute;
        }
        if(hour - t.hour < 0){
            hour+=24;
            hour-=t.hour;
            --day;
        }
        else{
            hour-=t.hour;
        }
        if(day-t.day < 0)
            day=0;
        else
            day-=t.day;
    }
    return *this;

}

Time Time::operator-(Time & t) {
    Time temp{*this};
    temp -= t;
    return temp;
}

Time Time::operator*(const int t) {
    int res;
    second*=t;
    if(second >= 60){
        res = second / 60;
        second = second % 60;
        minute+=res;
    }
    minute*=t;
    if(minute >= 60){
        res = minute / 60;
        minute = minute % 60;
        hour+=res;
    }
    hour*=t;
    if(hour >= 24){
        res = hour / 24;
        hour = hour % 60;
        day+=res;
    }
    day*=t;

    return *this;
}

bool operator==(const Time &t1, const Time &t2) {
    if(t1.day == t2.day && t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second)
        return true;
    else
        return false;
}

bool operator!=(const Time &t1, const Time &t2){

    if(t1.day != t2.day || t1.hour != t2.hour || t1.minute != t2.minute || t1.second != t2.second)
        return true;
    else
        return false;
}

bool operator>(const Time& t1, const Time &t2){

    if(t1.day > t2.day)
        return true;
    else if(t1.day == t2.day){
        if(t1.hour > t2.hour)
            return true;
        else if(t1.hour == t2.hour){
            if(t1.minute > t2.minute)
                return true;
            else if(t1.minute == t2.minute){
                if(t1.second > t2.second)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else return false;
    }
    else return false;
}

bool operator<(const Time& t1, const Time &t2){

    if(t1.day < t2.day)
        return true;
    else if(t1.day == t2.day){
        if(t1.hour < t2.hour)
            return true;
        else if(t1.hour == t2.hour){
            if(t1.minute < t2.minute)
                return true;
            else if(t1.minute == t2.minute){
                if(t1.second < t2.second)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool operator>=(const Time& t1, const Time &t2){
    if(t1 < t2)
        return false;
    else
        return true;
}

bool operator<=(const Time& t1, const Time &t2){

    if(t1 > t2)
        return false;
    else
        return true;
}


