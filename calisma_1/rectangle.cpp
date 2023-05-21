#include <iostream>

using namespace std;

class Rectangle{

private:

    int longSide;
    int shortSide;

public:

    void setSides(int LS,int SS);
    int area();
    int perimeter();
    void display();
    string name;
};

void Rectangle::setSides(int LS, int SS){

    longSide = LS;
    shortSide = SS;
    cout<<"Kisa Kenar: "<<longSide<<endl;
    cout<<"Uzun Kenar: "<<shortSide<<endl;

    if(longSide == shortSide){
        name = "Kare";
    }
    else{
        name = "Dikdortgen";
    }
}

int Rectangle::area(){

    return (longSide*shortSide);
}

int Rectangle::perimeter(){

    return(2*longSide+2*shortSide);
}

void Rectangle::display() {

    int i, j;
    for (i = 1; i <= shortSide; i++) {

        for (j = 1; j < longSide; j++) {
            cout << "* ";
        }
        cout << "*"<< endl;
    }
}


int main() {

    Rectangle R1,R2;

    R1.setSides(10,5);

    cout<<"Adi: "<< R1.name<<endl;
    cout<<"Alan: "<<R1.area()<<endl;
    cout<<"Cevre: "<<R1.perimeter()<<endl;
    R1.display();

    cout << endl<< endl;

    R2.setSides(3,3);

    cout<<"Adi: "<< R2.name<<endl;
    cout<<"Alan: "<<R2.area()<<endl;
    cout<<"Cevre: "<<R2.perimeter()<<endl;
    R2.display();

    return 0;
}
