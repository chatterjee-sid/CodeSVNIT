#include<iostream>
#include<iomanip>
using namespace std;

void matrix_input(int**, int, int);
void matrix_display(int**, int, int);

int main(){
    int m,n;
    cout<<"Enter dimensions of matrix: ";
    cin>>m>>n;
    int** matrix;
    matrix = new int*[m];
    for(int i=0;i<m;i++){
        matrix[i] = new int[n];
    }
    matrix_input(matrix, m, n);
    matrix_display(matrix, m, n);
}

void matrix_input(int** matrix, int m, int n){
    cout<<"Enter matrix elements"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter matrix["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
        }
    }
}

void matrix_display(int** matrix, int m, int n){
    cout<<"Matrix elements are as follows:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<setw(2)<<setfill('0')<<matrix[i][j]<<' ';
        cout<<endl;
    }
}