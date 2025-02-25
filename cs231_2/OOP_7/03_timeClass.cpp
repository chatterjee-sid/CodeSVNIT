#include<iostream>
#include<iomanip>
using namespace std;

class Time{
    int hh;
    int mm;
    int ss;
public:
    Time(int = 0, int = 0, int = 0);
    bool operator == (Time&);
    friend istream& operator >> (istream&, Time&);
    friend ostream& operator << (ostream&, Time&);
};

int main(){
    Time T1, T2;
    cout<<"T1? ";
    cin >> T1;
    cout<<"T2? ";
    cin >> T2;
    cout<<"T1 = "<<T1<<endl;
    cout<<"T2 = "<<T2<<endl;
    if(T1==T2){
        cout<<"Times are equal";
    } else {
        cout<<"Times are unequal";
    }
    return 0;
}

Time::Time(int h, int m, int s){
    hh = h;
    mm = m;
    ss = s;
    mm += ss/60;
    ss %= 60;
    hh += mm/60;
    mm %= 60;
}

bool Time::operator == (Time& T){
    if(T.hh==hh && T.mm==mm && T.ss==ss)
    return true;
    return false;
}

istream& operator >> (istream& is, Time& T){
    is >> T.hh >> T.mm >> T.ss;
    T.mm += T.ss/60;
    T.ss %= 60;
    T.hh += T.mm/60;
    T.mm %= 60;
    return is;
}

ostream& operator << (ostream& os, Time& T){
    os << setfill('0') << setw(2) << T.hh << ':' << setfill('0') << setw(2) << T.mm << ':' << setfill('0') << setw(2) << T.ss;
    return os;
}