#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A({3,8,7,1,12,6,4,2,11,13,10,9,5});
    cout << "A.size(): " << A.size() << endl;
    cout << "A.max_size(): " << A.max_size() << endl;
    cout << "A.capacity(): " << A.capacity() << endl;
    A.resize(A.capacity()+1);
    cout << "A.resize() => A.size(): " << A.size() << endl;
    cout << "A.resize() => A.capacity(): " << A.capacity() << endl;
    if (A.empty()) {
        cout << "The vector is empty." << endl;
    } else {
        cout << "The vector is not empty." << endl;
    }
    A.reserve(A.capacity()+1);
    cout << "A.reserve() => A.size(): " << A.size() << endl;
    cout << "A.reserve() => A.capacity(): " << A.capacity() << endl;
    return 0;
}