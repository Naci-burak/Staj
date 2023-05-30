#include <iostream>

using namespace std;

class Date{

private:
    int d,m,y;
public:

    Date(int cd, int cm, int cy);   //ctor

    void input();
    bool set(int cd, int cm, int cy);

    bool gecerli(int cd, int cm, int cy); // tarihin gecerliligini kontrol
    int ayKontrol();    // ay gun sayisi bildirimi dönecek

    //accessor
    int getMonth()const;
    int getDay()const;
    int getYear()const;

    void increment();   // tarihi 1 gün ileri atar
    int dayOfWeek();    // günü belirleme algoritması
    int compare(const Date& t); //2 tarihi karşılaştırır
    void showByDay();   // gün gösterimi
    void showByMonth(); // ay takvimi gösterimi

};

Date::Date(int cd, int cm, int cy) : d{cd} , m{cm}, y{cy} { }

void Date::input() {

    cout << "Tarih giriniz: ";
    cin >> d >> m >> y;

    if ( !(gecerli(d,m,y) ) ){
        input();
    }
}

int Date::ayKontrol() {
    int gunSayisi {0};

    switch (m) {

        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                gunSayisi=31;
                break;
        case 4: case 6: case 9: case 11:
                gunSayisi = 30;
                break;
        case 2:
                if( ( (y%100) == 0 && (y%400 == 0) ) || (y%100) != 0 && (y%4) == 0 ) {
                    gunSayisi = 29;
                }
                else{
                    gunSayisi = 28;
                }
                break;
    }
    return gunSayisi;
}

bool Date::gecerli(int cd, int cm, int cy) {

    int gunSayisi = ayKontrol();

    if( 1 <= cm <= 12 && 1 <= cd <= gunSayisi && 1 <= cy) {
        cout << "Tarih gecerli." << endl;
        return true;
    }
    else{
        cout << "Tarih gecersiz." << endl;
        return false;
    }

}


int Date::getDay()const {
    return d;
}

int Date::getMonth()const {
    return m;
}

int Date::getYear()const {
    return y;
}

bool Date::set(int cd, int cm, int cy){

    if( gecerli(cd,cm,cy) ){
        cout << "Tarih Gecerli." << endl;
        d = cd;
        m = cm;
        y = cy;
        return true;
    }
    else{
        cout << "Tarih Gecersiz." << endl;
        return false;
    }
}

void Date::increment() {
    int gunSayisi = ayKontrol();

    if(m != 12){
       if(d < gunSayisi){
            ++d;
       }
        else{
            d = 1;
            ++m;
        }
    }else{
        if(d < gunSayisi){
            ++d;
        }
        else{
            d = 1;
            m = 1;
            ++y;
        }
    }
}

int Date::dayOfWeek() {   
    int cy = y;
    static int arr[] = {0, 3, 2, 5, 0, 3, 5, 1, 4,6 ,2, 4};
    cy -= m < 3;
    return (y + y/4 - y/100 + y/400 + arr[m-1] + d) % 7;
}

int Date::compare(const Date &t) {

   if(y > t.y) return 1;

   else if(y == t.y){
       if(m > t.m) return 1;
       else if(m == t.m){
           if(d > t.d) return 1;
           else if(d == t.d) return 0;
           else return -1;
       }
       else return -1;
   }
   else return -1;
}

void Date::showByDay() {

    int x = dayOfWeek();
    const string day[7] = { "pazar", "pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi"};
    cout << day[x] << "  " << d << "/" << m << "/" << y ;

}


void Date::showByMonth() {

    static const string kisaltma[7] = {"Pa", "Pt", "Sa", "Ca", "Pe", "Cu", "Ct"};
    int gun = dayOfWeek(); // 5
    int gunSayisi = ayKontrol();
    int ay[5][7];
    int cd = 1;

    Date df(cd,m,y);        // ayın ilk günü belirlemek için yeni nesne
    int gunf = df.dayOfWeek();

    for (int i = 0; i <= 6; i++) {
        cout << kisaltma[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 6 && cd <= gunSayisi; j++) {
            if (i == 0 && j < gunf) {       // takvim ay görünümünü düzenlemek için
                ay[i][j] = 0;
                cout << ay[i][j] << "\t";
            }
            else{
                ay[i][j] = cd;
                cout << ay[i][j] << "\t";
                ++cd;
            }
        }
        cout << endl;
    }
}

int main(){


 Date d1 (12,11,2023);
 Date d2(29,5,2023);

 cout << "\nDate d1: ";
 d1.showByDay();
 cout << "\nDate d2: ";
 d2.showByDay();
 d2.increment();
 cout << "\nincrement, Date d2: ";
 d2.showByDay();
 cout << "\nShown by month, Date d2: \n\n";

 d2.showByMonth();
 cout << endl;

 int kont = d1.compare(d2);
 if(kont == -1)
 cout << "d1 tarihi d2 den once" << endl;
 else if (kont == 1)
 cout << "d1 tarihi d2 den sonra" << endl;
 else
 cout << "d1 tarihi d2 ye esit" << endl;

    return 0;
}
