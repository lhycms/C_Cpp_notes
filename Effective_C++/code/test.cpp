#include <iostream>


class Base {
};

class Derived : private Base {
};


int main() {
    Derived d1;
    Base *b1 = (Base*)(&d1);
    Base *b2 = static_cast<Base*>(&d1);

    return 0;
}