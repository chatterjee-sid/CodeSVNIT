#include<bits/stdc++.h>
using  namespace std;

void merge3(vector<int>& arr, int low, int first, int second, int high){
    vector<int> B1(first-low), B2(second-first), B3(high-second);
    for(int i=low;i<first;i++){
        B1[i-low] = arr[i];
    }
    for(int i=first;i<second;i++){
        B2[i-first] = arr[i];
    }
    for(int i=second;i<high;i++){
        B3[i-second] = arr[i];
    }
    int b1s = first-low, b2s = second-first, b3s = high-second;
    int i=0,j=0,k=0,l=low;
    while(i<b1s && j<b2s && k<b3s){
        if(B1[i]<=B2[j]){
            if(B1[i]<=B3[k]){
                arr[l++] = B1[i++];
            } else{
                arr[l++] = B3[k++];
            }
        } else{
            if(B2[j]<=B3[k]){
                arr[l++] = B2[j++];
            } else{
                arr[l++] = B3[k++];
            }
        }
    } while(i<b1s && j<b2s){
        if(B1[i]<=B2[j]){
            arr[l++] = B1[i++];
        } else{
            arr[l++] = B2[j++];
        }
    } while(i<b1s && k<b3s){
        if(B1[i]<=B3[k]){
            arr[l++] = B1[i++];
        } else{
            arr[l++] = B3[k++];
        }
    } while(j<b2s && k<b3s){
        if(B2[j]<=B3[k]){
            arr[l++] = B2[j++];
        } else{
            arr[l++] = B3[k++];
        }
    } while(i<b1s){
        arr[l++] = B1[i++];
    } while(j<b2s){
        arr[l++] = B2[j++];
    } while(k<b3s){
        arr[l++] = B3[k++];
    }
}
void mergesort3(vector<int>& arr,int low,int high){
    if(high-low<=1) return;
    if(high-low==2){
        if(arr[high-1]<arr[low]) swap(arr[high-1],arr[low]);
        return;
    }
    int first = low + (high-low)/3;
    int second = first + (high-low)/3;
    mergesort3(arr,low,first);
    mergesort3(arr,first,second);
    mergesort3(arr,second,high);
    merge3(arr,low,first,second,high);
}

int main(){
    cout<<"Average Case"<<endl;
    for(int i=0; i<10; i++){
        ifstream file("..\\Files\\File "+to_string(i+1)+".txt");
        vector<int> numbers;
        int num;
        while(file>>num){
            numbers.push_back(num);
        }
        cout<<"File "<<i+1<<endl;
        auto start = chrono::high_resolution_clock::now();
        mergesort3(numbers,0,numbers.size());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double,milli> time = end-start;
        cout<<"Average case time: "<<time.count()<<"ms"<<endl;
    }
    return 0;
}