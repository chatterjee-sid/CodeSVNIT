#include<iostream>
using namespace std;
class Array2;
class Array3;
class Array1{
    int array[100] = {0};
    int top = 0;
public:
    friend Array1 ArrayAdder(Array1, Array2, Array3);
    Array1(){}
    Array1(int*, int);
    void ArrayDisplay();
};
class Array2{
    int array[100] = {0};
    int top = 0;
public:
    friend Array1 ArrayAdder(Array1, Array2, Array3);
    Array2(){}
    Array2(int*, int);
    void ArrayDisplay();
};
class Array3{
    int array[100] = {0};
    int top = 0;
public:
    friend Array1 ArrayAdder(Array1, Array2, Array3);
    Array3(){}
    Array3(int*, int);
    void ArrayDisplay();
};
Array1::Array1(int* ArrayPt, int size){
    for(int i=0;i<size;i++){
        array[i] = *(ArrayPt+i);
    }
    top = size;
}
Array2::Array2(int* ArrayPt, int size){
    for(int i=0;i<size;i++){
        array[i] = *(ArrayPt+i);
    }
    top = size;
}
Array3::Array3(int* ArrayPt, int size){
    for(int i=0;i<size;i++){
        array[i] = *(ArrayPt+i);
    }
    top = size;
}
void Array1::ArrayDisplay(){
    for(int i=0;i<top;i++){
        cout<<array[i]<<' ';
    }
    cout<<endl;
}
void Array2::ArrayDisplay(){
    for(int i=0;i<top;i++){
        cout<<array[i]<<' ';
    }
    cout<<endl;
}
void Array3::ArrayDisplay(){
    for(int i=0;i<top;i++){
        cout<<array[i]<<' ';
    }
    cout<<endl;
}
Array1 ArrayAdder(Array1 A, Array2 B, Array3 C){
    int t = A.top;
    if(B.top > t) t = B.top;
    if(C.top > t) t = C.top;
    int K[t];
    for(int i=0;i<t;i++){
        K[i] = A.array[i] + B.array[i] + C.array[i];
    }
    Array1 S(K,t);
    return S;
}
int main(){
    int t1,t2,t3;
    cout<<"Enter size of Array1: ";
    cin>>t1;
    int K1[t1];
    cout<<"Enter Array1: ";
    for(int i=0;i<t1;i++){
        cin>>K1[i];
    }
    Array1 A1(K1,t1);
    cout<<"Enter size of Array2: ";
    cin>>t2;
    int K2[t2];
    cout<<"Enter Array2: ";
    for(int i=0;i<t2;i++){
        cin>>K2[i];
    }
    Array2 A2(K2,t2);
    cout<<"Enter size of Array3: ";
    cin>>t3;
    int K3[t3];
    cout<<"Enter Array3: ";
    for(int i=0;i<t3;i++){
        cin>>K3[i];
    }
    Array3 A3(K3,t3);
    cout<<"Arrays added: ";
    Array1 S = ArrayAdder(A1,A2,A3);
    S.ArrayDisplay();
}