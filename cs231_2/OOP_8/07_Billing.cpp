#include<iostream>
#include<vector>
using namespace std;

class Bill;
class Item{
protected:
    int itemno;
    string name;
    float price;
public:
    Item(int a, string b, float c){
        itemno = a;
        name = b;
        price = c;
    }
};

class DiscountedItem: public Item{
protected:
    int discount;
    float trueprice;
public:
    DiscountedItem(int a, string b, float c, int d) : Item(a,b,c){
        discount = d;
        trueprice = price * (100-d)/100;
    }
    void ItemInfo(){
        cout<<itemno<<' '<<name<<' '<<trueprice<<endl;
    };
    float itemprice(){
        return trueprice;
    }
};

class Bill{
public:
    float amount;
    vector<DiscountedItem> List;
    void display(){
        if(List.empty()){
            cout<<"List Empty"<<endl;
            return;
        }
        for(int i=0; i<List.size(); i++){
            DiscountedItem X = List[i];
            X.ItemInfo();
        }
    }
    void add(DiscountedItem X){
        List.push_back(X);
        amount += X.itemprice();
    }
};

int main(){
    Bill B;
    int n;
    cout<<"Enter no. of items: ";
    cin>>n;
    for(int i=0;i<n;i++){
        string a,temp;
        float b;
        int c;
        cout<<"Name? ";
        getline(cin,temp);
        getline(cin,a);
        cout<<"Price? ";
        cin>>b;
        cout<<"Discount%? ";
        cin>>c;
        DiscountedItem D(i+1,a,b,c);
        B.add(D);
        cout<<"------"<<endl;
    }
    cout<<"------"<<endl;
    B.display();
    cout<<"------"<<endl;
    cout<<"Total amount: "<<B.amount;
    return 0;
}