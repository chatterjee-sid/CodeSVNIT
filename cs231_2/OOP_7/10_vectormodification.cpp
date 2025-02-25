#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> A;
    A.assign(5,10);
    cout << "A.assign(5,10): ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    A.push_back(20);
    A.push_back(30);
    cout << "A.push_back(20), A.push_back(30): ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    A.pop_back();
    cout << "A.pop_back(): ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}