#include<iostream>
#include<vector>
using namespace std;

class Matrix1;
class Matrix2;

class Matrix1{
    vector<vector<int>> matrix;
    int row;
    int col;
public:
    friend Matrix1 MatrixAdder(const Matrix1&, const Matrix2&);
    Matrix1(){}
    Matrix1(const vector<vector<int>>& MatrixPt, int r, int c) : matrix(MatrixPt), row(r), col(c) {}
    void MatrixDisplay();
};

class Matrix2{
    vector<vector<int>> matrix;
    int row;
    int col;
public:
    friend Matrix1 MatrixAdder(const Matrix1&, const Matrix2&);
    Matrix2(){}
    Matrix2(const vector<vector<int>>& MatrixPt, int r, int c) : matrix(MatrixPt), row(r), col(c) {}
    void MatrixDisplay();
};

void Matrix1::MatrixDisplay(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
}

void Matrix2::MatrixDisplay(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
}

Matrix1 MatrixAdder(const Matrix1& A, const Matrix2& B){
    if(A.row != B.row || A.col != B.col){
        cout<<"Not Possible"<<endl;
        cout<<"Return Empty Matrix"<<endl;
        Matrix1 M;
        return M;
    }
    vector<vector<int>> K(A.row, vector<int>(A.col));
    for(int i=0;i<A.row;i++){
        for(int j=0;j<A.col;j++){
            K[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }
    Matrix1 S(K, A.row, A.col);
    return S;
}

int main(){
    int r1,c1,r2,c2;
    cout<<"Enter dimensions of Matrix1: ";
    cin>>r1>>c1;
    vector<vector<int>> K1(r1, vector<int>(c1));
    cout<<"Enter Matrix1: "<<endl;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>K1[i][j];
        }   
    }
    Matrix1 A1(K1, r1, c1);
    cout<<"Enter dimensions of Matrix2: ";
    cin>>r2>>c2;
    vector<vector<int>> K2(r2, vector<int>(c2));
    cout<<"Enter Matrix2: "<<endl;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>K2[i][j];
        }   
    }
    Matrix2 A2(K2, r2, c2);
    Matrix1 S = MatrixAdder(A1, A2);
    cout<<"Returned Matrix: "<<endl;
    S.MatrixDisplay();
    return 0;
}