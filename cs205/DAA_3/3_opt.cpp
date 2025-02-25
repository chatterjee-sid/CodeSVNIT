#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> A(n);
    int zeropt = 0, onept = 0, twopt = n-1;
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    while(onept <= twopt){
        if(A[onept]==0){
            swap(A[onept],A[zeropt]);
            onept++;
            zeropt++;
        } else if(A[onept]==1){
            onept++;
        } else{
            swap(A[onept],A[twopt]);
            twopt--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
    return 0;
}

/*
2 0 1 0 0 0
z,o,t = 0,0,5
0 0 1 0 0 2
z,o,t  = 0,0,4
0 0 1 0 0 2
z,o,t = 1,1,4
0 0 1 0 0 2
z,o,t = 2,2,4
0 0 1 0 0 2
z,o,t = 2,3,4
0 0 0 1 0 2
*/