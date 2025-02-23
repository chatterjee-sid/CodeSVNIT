//1. Implement a binary search algorithm (Check the element one by one from the beginning). Use the sorting arrays computed by the sorting algorithm as inputs. In addition. If this number can be found, print out the corresponding index, otherwise print out “This element cannot be found!”.
#include<iostream>
using namespace std;
int main(){
    int array[] = {3,8,7,1,12,6,4,2,11,13,10,9,5};
    int len = sizeof(array)/sizeof(int);
    int L=0, R=len-1;
    for(int i=0;i<len;i++){
        for(int j=i;j>=0;j--){
            if(array[j+1]<array[j]){
                int p = array[j];
                array[j] = array[j+1];
                array[j+1] = p;
            }
        }
    }
    int data;
    cin>>data;
    int flag=1;
    while(L<=R){
        int M = (L+R)/2;
        if(array[M]<data){
            L=M+1;
        } else if(array[M]>data){
            R=M-1;
        } else{
            cout<<"Index: "<<M;
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<"This element cannot be found...";
    }
}