/*02. WAP to implement a queue data structure and perform basic operations of it.
Implement functions:
A. enqueue(): This function should take one argument of type integer. It enqueues the element
into the queue.
B. dequeue(): It removes the element from the front of the queue and in turn, returns the
element being dequeued or removed. In case the queue is empty, return -1
C. front(): It returns the element being kept at the front of the queue. In case queue is
empty, it returns -1
D. is Empty(): It returns a boolean value indicating whether the queue is empty or not.
*/
#include<iostream>
using namespace std;
#define MAX 10
#define MIN -1
class queue{
public:
    int frontptr;
    int rearptr;
    int val[MAX];
    queue(){
        this->frontptr=MIN;
        this->rearptr=MIN;
    }
    void enqueue(int data){
        if(rearptr==MAX-1){
            if(frontptr==MIN){
                cout<<"Overflow"<<endl;
                return;
            } else{
                for(int i=frontptr+1;i<=rearptr;i++){
                    val[i-1-frontptr]=val[i];
                }
                rearptr-=(frontptr+1);
                frontptr=-1;
            }
        }
        val[++rearptr]=data;
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        } else{
            int x=front();
            frontptr++;
            return x;
        }
    }
    int front(){
        if(isEmpty()){
            return -1;
        } else{
            return val[frontptr+1];
        }
    }
    int isEmpty(){
        if(rearptr==frontptr){
            return 1;
        } else{
            return 0;
        }
    }
    void display(){
        for(int i=frontptr;i<rearptr;i++){
            cout<<val[i+1]<<' ';
        }
        cout<<endl;
    }
};
int main(){
    queue one;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Enqueue"<<endl;
        cout<<"\t2. Dequeue"<<endl;
        cout<<"\t3. Front"<<endl;
        cout<<"\t4. isEmpty"<<endl;
        cout<<"\t0. Exit"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            int value;
            cout<<"Enter value to enqueue: ";
            cin>>value;
            one.enqueue(value);
        }
        else if(choice==2) cout<<"Dequeued: "<<one.dequeue()<<endl;
        else if(choice==3) cout<<"Front: "<<one.front()<<endl;
        else if(choice==4){
            if(one.isEmpty()) cout<<"The queue is empty"<<endl;
            else cout<<"The queue is not empty"<<endl;
        } else if(choice==0){
            cout<<"Thank you"<<endl;
            break;
        } else{
            cout<<"Invalid option"<<endl;
        }
        cout<<"Current Queue: ";
        one.display();
    }
}