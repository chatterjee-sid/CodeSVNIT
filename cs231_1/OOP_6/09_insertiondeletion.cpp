#include<iostream>
using namespace std;

void insertElement(int*, int&, int, int);
void deleteElement(int*, int&, int);
void display(int*, int&);

int main(){
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    cout<<"Enter array: ";
    int *ptr = new int[n];
    for(int i=0;i<n;i++){
        cin>>*(ptr+i);
    }
    while(1){
        cout<<"Menu"<<endl;
        cout<<"\t1. Insert"<<endl;
        cout<<"\t2. Delete"<<endl;
        cout<<"\t0. Exit"<<endl;
        int ch;
        cout<<"Enter choice: ";
        cin>>ch;
        if(ch==0){
            break;
        } else if(ch==1){
            int pos,ele;
            cout<<"No. of elements: "<<n<<endl;
            cout<<"Enter index: ";
            cin>>pos;
            cout<<"Enter element: ";
            cin>>ele;
            insertElement(ptr,n,pos,ele);
        } else if(ch==2){
            int pos;
            cout<<"No. of elements: "<<n<<endl;
            cout<<"Enter index: ";
            cin>>pos;
            deleteElement(ptr,n,pos);
        } else{
            cout<<"Error..."<<endl;
        }
        display(ptr,n);
    }
    delete[] ptr;
    return 0;
}

void insertElement(int* a, int& size, int pos, int ele){
    if (pos>size){
        cout<<"Position overflow";
        cout<<": Pushed_back"<<endl;
        pos = size;
    } else if(pos<0){
        cout<<"Position underflow";
        cout<<": Pushed_front"<<endl;
        pos = 0;
    }
    for(int i=size; i>pos; i--){
        *(a+i) = *(a+i-1);
    }
    *(a+pos) = ele;
    size++;
    cout<<"Insertion Successful"<<endl;
}

void deleteElement(int* a, int& size, int pos){
    if (pos>=size){
        cout<<"Position overflow";
        cout<<": Unsuccessful deletion"<<endl;
        return;
    } else if(pos<0){
        cout<<"Position underflow";
        cout<<": Unsuccessful deletion"<<endl;
        return;
    }
    for(int i=pos;i<size-1;i++){
        *(a+i) = *(a+i+1);
    }
    size--;
    cout<<"Deletion Successful"<<endl;
}

void display(int* a, int& size){
    for(int i=0;i<size;i++){
        cout<<*(a+i)<<' ';
    }
    cout<<endl;
}