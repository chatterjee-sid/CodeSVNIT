#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no. of cities: ";
    cin>>n;
    cin.ignore();
    string* cities = new string[n];
    for(int i=0; i<n; i++){
        getline(cin,cities[i]);
    }
    cout<<"-----"<<endl;
    for(int i=0; i<n; i++){
        if(cities[i][0]=='B' || cities[i][0]=='C' || cities[i][0]=='b' || cities[i][0]=='c'){
            cout<<cities[i]<<endl;
        }
    }
    delete[] cities;
    return 0;
}