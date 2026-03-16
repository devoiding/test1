#include <iostream>

using namespace std;

class dummy {
        int x;
    public: 
        dummy();
        dummy(int in_x);
        ~dummy();
        int get_x() const;
        void set_x(int in_x);
};

int main(void) {
    dummy d1, d2(10);
    cout << "d1.x = " << d1.get_x() << endl;
    cout << "d2.x = " << d2.get_x() << endl;
}

dummy::dummy() {
    x = 0;
}

dummy::dummy(int in_x) {
    x = in_x;
}

dummy::~dummy() {
    cout << "The destructor is called" << endl;
}

int dummy::get_x() const {
    return x;
}

void dummy::set_x(int in_x) {
    x = in_x;
}