#include <iostream>
#include <conio.h>

class Car{
public:
    virtual Car* clone() = 0;
    virtual void vprint(std::ostream& os)const = 0;

    virtual ~Car(){ };

    virtual void start(){
        std::cout << "Araba calisti.\n";
    }
    virtual void run(){

        std::cout << "Araba gidiyor.\n";
    }
    virtual void stop(){
        std::cout << "Araba durdu.\n";
    }
    void maintain();


};

class Bmw : public Car {

    virtual void vprint(std::ostream& os)const override{
        os << "Araba --> Bmw\n";
    }

    Bmw* clone()override{       // covariance
        return new Bmw(*this);
    }

    virtual void start()override{
        std::cout << "Bmw calisti.\n";
    }
    virtual void run()override{

        std::cout << "Bmw gidiyor.\n";
    }
    virtual void stop()override{
        std::cout << "Bmw durdu.\n";
    }

};


class Mercedes : public  Car {

    virtual void vprint(std::ostream& os)const override{
        os << "Araba --> Mercedes\n";
    }

    Mercedes* clone()override{
        return new Mercedes(*this);
    }

    virtual void start()override{
        std::cout << "Mercedes calisti.\n";
    }
    virtual void run()override{

        std::cout << "Mercedes gidiyor.\n";
    }
    virtual void stop()override{
        std::cout << "Mercedes durdu.\n";
    }



};


class Volvo : public Car {

    virtual void vprint(std::ostream& os)const override{
        os << "Araba --> Volvo\n";
    }

    Volvo* clone()override{
        return new Volvo(*this);
    }

    virtual void start()override{
        std::cout << "Volvo calisti.\n";
    }
    virtual void run()override{

        std::cout << "Volvo gidiyor.\n";
    }
    virtual void stop()override{
        std::cout << "Volvo durdu.\n";
    }



};

class Fiat : public Car{

    virtual void vprint(std::ostream& os)const override{
        os << "Araba --> Fiat\n";
    }

    Fiat* clone()override{
        return new Fiat(*this);
    }

    virtual void start()override{
        std::cout << "Fiat calisti.\n";
    }
    virtual void run()override{

        std::cout << "Fiat gidiyor.\n";
    }
    virtual void stop()override{
        std::cout << "Fiat durdu.\n";
    }


};


class Fiat124 : public Fiat{

    virtual void vprint(std::ostream& os)const override{
        os << "Araba --> Fiat124\n";
    }

    Fiat124* clone()override{
        return new Fiat124(*this);
    }

    virtual void start()override{
        std::cout << "Fiat124 calisti.\n";
    }
    virtual void run()override{

        std::cout << "Fiat124 gidiyor.\n";
    }
    virtual void stop()override{
        std::cout << "Fiat124 durdu.\n";
    }


};

void car_game(Car* p){
    p->start();
    p->run();
    p->stop();
    std::cout << "---------------\n";
}

Car* create_random_car(){
    switch (rand()%4) {
        case 0: return new Bmw;
        case 1: return new Mercedes;
        case 2: return new Volvo;
        case 3: return new Fiat;
        case 4: return new Fiat124;
    }

}

int main() {


    for(;;){
        auto p = create_random_car();
        car_game(p);
        _getch();
        delete p;
    }


}
