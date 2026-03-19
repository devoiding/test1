// Class ARRAY

#include <iostream>
#include <cmath>

using namespace std;

class ARRAY {
    int n;
    int *p;
public:
    ARRAY(int in_n);
    ~ARRAY();
    int get_n(int i);
    void set();
    void print();
    
};  

int main(void) {
    ARRAY a(10);
    a.set();
    a.print();
    return 0;
}

ARRAY::ARRAY(int in_n) {
    n = in_n;
    p = new int[n];
    if (!p) {
        cout << "Error allocating memory try again" << endl;
    }
}

ARRAY::~ARRAY() {
    delete [] p;
}

int ARRAY::get_n(int i) {
    if (i < n) {
        return p[i];
    }

    else {
        cout << "Index out of bounds try again" << endl;
        return 1;
    }
}

void ARRAY::print() {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void ARRAY::set() {
    for (int i = 0; i < n; i++) {
        p[i] = pow(i, 2);
    }
}