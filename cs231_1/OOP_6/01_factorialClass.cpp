#include<iostream>
using namespace std;

class Factorial{
public:
    int n,fact;
    Factorial();
    Factorial(Factorial&);
};

int main(){
    Factorial p;
    Factorial p1(p);
    cout<<"Factorial of "<<p.n<<" is "<<p.fact;
    return 0;
}

Factorial::Factorial(){
    cout<<"Enter n: ";
    cin>>n;
    fact = 1;
}

Factorial::Factorial(Factorial& A){
    n = A.n;
    fact = A.fact;
    for(int i=2; i<=A.n; i++){
        fact *= i;
    }
    A.fact = fact;
}