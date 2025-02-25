#include<iostream>
using namespace std;

class ITEM{
public:
    int item_code;
    float item_rate;
    int quantity;
    ITEM(){};
    ITEM(int item_code, float item_rate, int quantity){
        this->item_code = item_code;
        this->item_rate = item_rate;
        this->quantity = quantity;
    }
    float amount(){
        return item_rate * quantity;
    }    
};

int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    ITEM** item_list = new ITEM*[n];
    for(int i=0; i<n; i++){
        cout<<"Item no. "<<i+1<<endl;
        int a,c;
        float b;
        cout<<"Item Code: ";
        cin>>a;
        cout<<"Item Rate: ";
        cin>>b;
        cout<<"Quantity: ";
        cin>>c;
        item_list[i] = new ITEM(a,b,c);
    }
    float sum = 0;
    cout<<"Code\tAmount"<<endl;
    for(int i=0; i<n; i++){
        cout<<item_list[i]->item_code<<'\t'<<item_list[i]->amount()<<endl;
        sum += item_list[i]->amount();
    }
    cout<<"----------"<<endl;
    cout<<"Total\t"<<sum<<endl;
    for(int i=0; i<n; i++){
        delete item_list[i];
    }
    delete[] item_list;
    return 0;
}