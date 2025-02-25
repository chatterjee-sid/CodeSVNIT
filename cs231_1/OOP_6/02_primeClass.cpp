#include<iostream>
#include<cmath>
using namespace std;

class PrimeCheck{
public:
    int n;
    bool prime;
    PrimeCheck(int);
};

int main(){
    int x;
    cout<<"Enter x: ";
    cin>>x;
    PrimeCheck P(x);
    if (P.prime){
        cout<<"x is prime";
    } else{
        cout<<"x is not prime";
    }
    return 0;
}

PrimeCheck::PrimeCheck(int x){
    n = x;
    prime = true;
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
            prime = false;
            break;
        }
    }
}