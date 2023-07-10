#include <iostream>


class Counter{
public:
    Counter(int val = 0);
    Counter& operator++();
    Counter operator++(int);
    Counter& operator--();
    Counter operator--(int);
    Counter& operator+=(int);
    Counter& operator-=(int);
    operator int()const;
    friend std::ostream& operator<<(std::ostream& os , const Counter& x);

private:
    int mval;

};

Counter::Counter(int val) : mval{val} { }

Counter &Counter::operator++() {
    ++mval;
    return *this;
}


Counter Counter::operator++(int) {
    Counter temp{*this};
    operator++();
    return temp;
}

Counter &Counter::operator--() {
    --mval;
    return *this;
}


Counter Counter::operator--(int) {
    Counter temp{*this};
    operator--();
    return temp;
}

Counter &Counter::operator+=(int val) {
    mval += val;
    return *this;
}


Counter &Counter::operator-=(int val) {
    mval -= val;
    return *this;
}

Counter::operator int() const {
    return mval;
}

std::ostream & operator<<(std::ostream& os, const Counter& c){

    return os << c.mval;

}


int main() {

    Counter c{4};

    for (int i = 0 ; i < 10 ; i++){
        ++c;
    }

    std::cout << "c= " << c << "\n";

    int ival = c;
    //int ival = c.operator int();
    std::cout << "ival =" << ival << "\n";

    return 0;

}
