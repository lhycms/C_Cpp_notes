#include <iostream>


class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x_value=0, int y_value=0) : x(x_value), y(y_value)
    {   }
    /*
        The above use of Initializer list is optional as the
        constructor can also be written as:

        Point(int i = 0, int j = 0) {
            x = i;
            y = j;
        }

    */

   // member function 1
   int getX() const {return x;}

   // member function 2
   int getY() const {return y;}
};


int main() {
    Point t1(10, 15);
    std::cout << "x = " << t1.getX() << ", ";
    std::cout << "y = " << t1.getY() << std::endl;
    return 0;
}