#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> A({3,8,7,1,6,4,2});
    cout<<"A.begin(): "<<*(A.begin())<<endl;
    cout<<"A.end()-1: "<<*(A.end()-1)<<endl;
    cout<<"A.rbegin(): "<<*(A.rbegin())<<endl;
    cout<<"A.rend()-1: "<<*(A.rend()-1)<<endl;
    return 0;
}