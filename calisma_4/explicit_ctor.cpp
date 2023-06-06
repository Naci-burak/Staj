#include <iostream>

using namespace std;

class Myclass{
public:
    Myclass();
    ~Myclass();
    explicit Myclass(int);
};

class Myclass_2{
public:
    Myclass_2();
    ~Myclass_2();
    Myclass_2(int);

};

Myclass::Myclass() {
    cout << "default ctor(this):" << this <<"\n";
}

Myclass::~Myclass() {
    cout << "destructor (this)" << this << "\n";
}

Myclass::Myclass(int) {
    cout << "Myclass(int)(this)" << this << "\n";
}

Myclass_2::Myclass_2() {
    cout << "Mc_2 default ctor(this):" << this <<"\n";
}

Myclass_2::~Myclass_2() {
    cout << "Mc_2 destructor (this)" << this << "\n";
}

Myclass_2::Myclass_2(int) {
    cout << "Myclass_2(int)(this)" << this << "\n";
}

void func(Myclass);
void foo(Myclass_2);

int main() {

    int val = 10;
    Myclass_2 m2;
    m2 = val;
    //foo(val);

    //explicit ctor
    int ival = 10;
    Myclass m;
    m = static_cast<Myclass>(ival); // cast operatoru ile dönüşüm yapılması gerekir.
    //func(Myclass);  // cast edilmemiş error

    return 0;
}
