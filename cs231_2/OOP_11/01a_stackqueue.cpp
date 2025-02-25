#include<iostream>
using namespace std;

class list{
protected:
    int *values;
    int limit;
public:
    list(int a){
        values = new int[a];
        limit = a;
    }
    virtual bool store(int) = 0;
    virtual int retrieve() = 0;
    ~list(){
        delete[] values;
    }
};

class stack: virtual public list{
    int top;
public:
    stack(int a) : list(a){
        top = 0;
    }
    bool store(int a) override{
        if(top==limit) return false;
        values[top] = a;
        top++;
        return true;
    }
    int retrieve() override{
        if(top==0) return INT32_MIN;
        top--;
        return values[top];
    }
};

class queue: virtual public list{
    int front, rear;
public:
    queue(int a) : list(a){
        front = -1;
        rear = -1;
    }
    bool store(int a) override{
        if(front==-1){
            front = 0;
            rear = 1;
            values[0] = a;
            return true;
        }
        if(rear==front){
            return false;
        }
        values[rear] = a;
        rear = (rear+1)%limit;
        return true;
    };
    int retrieve() override{
        if(front==-1){
            return INT32_MIN;
        }
        int p = values[front];
        front = (front+1)%limit;
        if(front==rear){
            front = -1;
            rear = -1;
        }
        return p;
    };
};

int main(){
    stack S(10);
    queue Q(10);
    int ch;
    while(1){
        cout<<"MENU"<<endl;
        cout<<"1. S.store()"<<endl;
        cout<<"2. S.retrieve()"<<endl;
        cout<<"3. Q.store()"<<endl;
        cout<<"4. Q.retrieve()"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        if(ch==1){
            int x;
            cout<<"Enter value to store: ";
            cin>>x;
            if(S.store(x)){
                cout<<"Stored successfully"<<endl;
            } else{
                cout<<"Stack overflowed"<<endl;
            }
        } else if(ch==2){
            int p = S.retrieve();
            if(p==INT32_MIN){
                cout<<"Stack underflowed"<<endl;
            } else{
                cout<<"Returned "<<p<<endl;
            }
        } else if(ch==3){
            int x;
            cout<<"Enter value to store: ";
            cin>>x;
            if(Q.store(x)){
                cout<<"Stored successfully"<<endl;
            } else{
                cout<<"Queue overflowed"<<endl;
            }
        } else if(ch==4){
            int p = Q.retrieve();
            if(p==INT32_MIN){
                cout<<"Queue underflowed"<<endl;
            } else{
                cout<<"Returned "<<p<<endl;
            }
        } else if(ch==0){
            cout<<"Thank you"<<endl;
            break;
        } else{
            cout<<"INVALID INPUT"<<endl;
        }
    }
    return 0;
}