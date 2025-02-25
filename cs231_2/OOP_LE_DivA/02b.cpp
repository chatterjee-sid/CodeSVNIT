#include<iostream>
#include<vector>
using namespace std;

class Product{
protected:
    string name;
    float price;
public:
    Product(string name, float price){
        this->name = name;
        this->price = price;
    }
    virtual void getDetails() = 0;
};

class Electronics : public Product{
public:
    Electronics(string name, float price) : Product(name, price){}
    void getDetails() override{
        cout<<"Name: "<<name<<endl;
        cout<<"Category: Electronics"<<endl;
        cout<<"Price: Rs."<<price<<endl;
    }
};

class Clothing : public Product{
public:
    Clothing(string name, float price) : Product(name, price){}
    void getDetails() override{
        cout<<"Name: "<<name<<endl;
        cout<<"Category: Clothing"<<endl;
        cout<<"Price: Rs."<<price<<endl;
    }
};

class Food : public Product{
public:
    Food(string name, float price) : Product(name, price){}
    void getDetails() override{
        cout<<"Name: "<<name<<endl;
        cout<<"Category: Food"<<endl;
        cout<<"Price: Rs."<<price<<endl;
    }
};

int main(){
    vector<Product*> Itemlist;
    float bill = 0;
    while(1){
        char ch;
        cout<<"Menu:"<<endl;
        cout<<"1. Add item"<<endl;
        cout<<"2. Show bill till now"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>ch;
        if(ch=='1'){
            string name;
            char cat;
            float price;
            while(1){
                cout<<"Category values:"<<endl;
                cout<<"Electronics"<<": 1"<<endl;
                cout<<"Clothing"<<": 2"<<endl;
                cout<<"Food"<<": 3"<<endl;
                cout<<"Enter category value: ";
                cin>>cat;
                if(cat!='1' && cat!='2' && cat!='3'){
                    cout<<"Invalid category"<<endl;
                } else{
                    break;
                }
            }
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Price: ";
            cin>>price;
            bill += price;
            if(cat=='1'){
                Itemlist.push_back(new Electronics(name, price));
            } else if(cat=='2'){
                Itemlist.push_back(new Clothing(name, price));
            } else{
                Itemlist.push_back(new Food(name, price));
            }
            cout<<"Item recorded"<<endl;
        } else if(ch=='2'){
            for(auto item: Itemlist){
                item->getDetails();
                cout<<endl;
            }
            cout<<"Total Bill: "<<bill<<endl;
        } else if(ch=='0'){
            cout<<"Thank you"<<endl;
            for(auto item: Itemlist){
                delete item;
            }
            break;
        } else{
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}