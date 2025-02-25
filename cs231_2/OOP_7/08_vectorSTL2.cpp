#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> A({3,8,7,1,6,4,2});
    cout<<"A.front(): "<<A.front()<<endl;
    cout<<"A.back(): "<<A.back()<<endl;
    int *pos = A.data();
    for(int i=0;i<A.size();i++){
        cout<<*pos++<<' ';
    }
    return 0;
}