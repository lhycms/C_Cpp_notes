#include <iostream>



class Interval {

private:
    int x, y;

public:
    // Constructor function
    Interval() = default;
    Interval(int x_value, int y_value):
                            x(x_value),
                            y(y_value) {
        std::cout << "Calling constructor function...\n";
    }


    // Copy Constructor function
    Interval(const Interval &i):
                            x(i.x),
                            y(i.y) {
        std::cout << "Calling copy constructor function...\n";
    }


    // Assignment Operator
    Interval& operator=(const Interval &i) {
        x = i.x;
        y = i.y;
        std::cout << "Calling assignment operator...\n";

        return *this;
    }

};


int main() {
    Interval interval = {1, 2};
    Interval interval_2 = interval;
    interval_2 = interval;

    return 0;
}