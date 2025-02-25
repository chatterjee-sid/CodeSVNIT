#include<iostream>
using namespace std;

int main(){
    while(1){
        int run=1;
        int n;
        cout<<"Enter number: ";
        cin>>n;
        if(n<=0){
            cout<<"Please enter a positive number"<<endl;
        } else if(n==1){
            cout<<"Not Prime"<<endl;
        } else{
            int flag = 1;
            for(int i=2;i<=n/2;i++){
                if(n%i==0){
                    cout<<"Not Prime"<<endl;
                    flag = 0;
                    break;
                }
            }
            if(flag) cout<<"Prime"<<endl;
        }
        char choice='z';
        while(choice!='n' && choice!='y'){
            cout<<"Wish to try again? (y/n) ";
            cin>>choice;
            if(choice=='n'){
                cout<<"Thank you"<<endl;
                run = 0;
                break;
            }
        }
        if(!run) break;
    }
    return 0;
}