//03. Create a system to manage orders in a restaurant using a circular queue. The system should allow customers to place orders, kitchen staff to process orders, and waitstaff to deliver orders to tables, all while efficiently managing the queue of orders with a circular structure.
#include<iostream>
#include<string>

using namespace std;
#define MAX 10
#define MIN -1
class queue{
public:
    int frontptr;
    int rearptr;
    string val[MAX];
    queue(){
        this->frontptr=MIN;
        this->rearptr=MIN;
    }
    void enqueue(string data){
        if(isFull()){
            cout<<"Please wait, previous task is in process."<<endl;
            return;
        }
        if(isEmpty()){
            frontptr=MIN+1;
        }
        rearptr=(rearptr+1)%MAX;
        val[rearptr]=data;
    }
    string dequeue(){
        if(isEmpty()){
            return NULL;
        }
        string x=val[frontptr];
        if(rearptr==frontptr){
            frontptr=MIN;
            rearptr=MIN;
        } else{
            frontptr=(frontptr+1)%MAX;
        }
        return x;
    }
    int isEmpty(){
        if(frontptr==-1){
            return 1;
        } else{
            return 0;
        }
    }
    int isFull(){
        if((rearptr+1)%MAX==frontptr){
            return 1;
        } else{
            return 0;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Empty"<<endl;
            return;
        }
        int i=frontptr;
        while(i!=(rearptr+1)%MAX){
            cout<<val[i]<<" -> ";
            i=(i+1)%MAX;
        }
        cout<<endl;
    }
};
int main(){
    queue customer,kitchen,waitstaff;
    while(1){
        cout<<"Restaurant simulator"<<endl;
        cout<<"\t1. Take order from customer"<<endl; //customer.enqueue
        cout<<"\t2. Add order to cooklist"<<endl; //customer.dequeue, kitchen.enequeue
        cout<<"\t3. Pass dish to waitstaff"<<endl; //kitchen.dequeue, waitstaff.enqueue
        cout<<"\t4. Serve the dist"<<endl; //waitstaff.dequeue
        cout<<"\t0. Exit"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            string order;
            cout<<"Take order: ";
            cin.ignore();
            getline(cin,order);
            if(customer.isFull()){
                cout<<"Order List is full! Please add them to cooklist first!!"<<endl;
            } else{
                customer.enqueue(order);
                cout<<"Order noted!"<<endl;
            }
        } else if(choice==2){
            if(kitchen.isFull()){
                cout<<"Cooklist is full! Please pass them to waitstaff first!!"<<endl;
            } else if(customer.isEmpty()){
                cout<<"Phew! No Pending orders."<<endl;
            } else{
                kitchen.enqueue(customer.dequeue());
                cout<<"Added to cooklist!"<<endl;
            }
        } else if(choice==3){
            if(waitstaff.isFull()){
                cout<<"Waitstaff can\'t take more dishes as of now! Serve the dishes to the customers first!!"<<endl;
            } else if(kitchen.isEmpty()){
                if(customer.isEmpty()){
                    cout<<"Phew! No Pending orders."<<endl;
                } else{
                    cout<<"Nothing in cooklist, but customers do have some orders."<<endl;
                }
            } else{
                waitstaff.enqueue(kitchen.dequeue());
                cout<<"Passed dish to waitstaff!"<<endl;
            }
        } else if(choice==4){
            if(waitstaff.isEmpty()){
                if(kitchen.isEmpty()){
                    if(customer.isEmpty()){
                        cout<<"Phew! No Pending orders."<<endl;
                    } else{
                        cout<<"Waiters don\'t have anything to serve, but customers do have orders."<<endl;
                    }
                } else{
                    cout<<"Waiters don\'t have anything to serve, but the kitchen is ready with dishes."<<endl;
                }
            } else{
                cout<<"A "<<waitstaff.dequeue()<<" has been served!"<<endl;
            }
        } else if(choice==0){
            cout<<"Thank you. Restaurant simulator OFF"<<endl;
            break;
        } else{
            cout<<"Invalid operation."<<endl;
        }
        cout<<"Order List: ";
        customer.display();
        cout<<"Cook List: ";
        kitchen.display();
        cout<<"Serve List: ";
        waitstaff.display();
    }
}