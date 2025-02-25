#include<iostream>
using namespace std;

class shopping{
public:
    int count;
    int code[1000] = {0};
    int price[1000] = {0};
    int bill;
    shopping(){
        count=0;
        bill=0;
    }
    void additem(int,int);
    void removeitem(int);
    void display();
};

void shopping::additem(int a, int b){
    if(count==1000){
        cout<<"Limit reached"<<endl;
        return;
    }
    for(int i=0;i<count;i++){
        if(code[i]==a){
            bill -= price[i];
            price[i] = b;
            bill += price[i];
            cout<<"Updated successfully"<<endl;
            return;
        }
    }
    code[count] = a;
    price[count] = b;
    bill += price[count];
    count++;
    cout<<"Added successfully"<<endl;
}

void shopping::removeitem(int a){
    int idx = -1;
    for(int i=0; i<count; i++){
        if(code[i]==a){
            idx = i;
            break;
        }
    }
    if(idx==-1){
        cout<<"Nothing to remove"<<endl;
        return;
    }
    bill -= price[idx];
    for(int i=idx; i<count-1; i++){
        code[i] = code[i+1];
        price[i] = price[i+1];
    }
    code[count-1] = 0;
    price[count-1] = 0;
    count--;
    cout<<"Deleted successfully"<<endl;
}

void shopping::display(){
    cout<<"-- Shopping List --"<<endl;
    for(int i=0;i<count;i++){
        cout<<code[i]<<' '<<price[i]<<endl;
    }
}

int main(){
    shopping list;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Add"<<endl;
        cout<<"\t2. Remove"<<endl;
        cout<<"\t3. Display"<<endl;
        cout<<"\t4. Bill"<<endl;
        cout<<"\t0. Exit"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            int code,price;
            cout<<"Code to add? ";
            cin>>code;
            cout<<"Price? ";
            cin>>price;
            list.additem(code,price);
            cout<<"----"<<endl;
        } else if(choice==2){
            if(list.count==0){
                cout<<"Nothing to remove"<<endl;
            }
            else{
                int code;
                cout<<"Code to remove? ";
                cin>>code;
                list.removeitem(code);
            }
            cout<<"----"<<endl;
        } else if(choice==3){
            list.display();
        } else if(choice==4){
            cout<<"Total Bill: "<<list.bill<<endl;
            cout<<"----"<<endl;
        } else if(choice==0){
            cout<<"Thank you"<<endl;
            break;
        } else{
            cout<<"Invalid choice"<<endl;
            cout<<"----"<<endl;
        }
    }
}