#include <iostream>

using namespace std;

class point {
    int x, y;
public:
    point();
    point(int in_x, int in_y);

    void print() const;
    void set_xy(int in_x, int in_y);
};

int main(void) {
    point p1, p2(3,4), p3(5,6);
    p1.print();
    p2.print();
    p3.print();
}

point::point() {
    x = 0;
    y = 0;
}

point::point(int in_x, int in_y) {
    x = in_x;
    y = in_y;
}

void point::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

void point::set_xy(int in_x, int in_y) {
    x = in_x;
    y = in_y;
}