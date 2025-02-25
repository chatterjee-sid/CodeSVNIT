#include<iostream>
using namespace std;
void mysort(string* C, int N){
    for(int i=0; i<N; i++){
        int smol;
        smol = i;
        for(int j=i+1; j<N; j++){
            if(C[j]<C[smol]){
                smol = j;
            }
        }
        string temp = C[i];
        C[i] = C[smol];
        C[smol] = temp;
    }
}

int main(){
    int n;
    cout<<"Enter no. of countries: ";
    cin>>n;
    cin.ignore();
    cout<<"Enter countries: "<<endl;
    string* countries = new string[n];
    for(int i=0; i<n; i++){
        getline(cin, countries[i]);
    }
    mysort(countries, n);
    cout<<endl;
    cout<<"Countries in order: "<<endl;
    for(int i=0; i<n; i++){
        cout<<countries[i]<<endl;
    }
    return 0;
}