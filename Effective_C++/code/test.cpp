#include <iostream>
#include <initializer_list>


class MyClass {
private:
    int a, b;

public:
    // Constructor
    MyClass(int a_value, int b_value) {
        std::cout << "Calling Constructor...\n";
        a = a_value;
        b = b_value;
    }

    // Initializer list constructor (serve as `Conversion Constructor` at the same time)
    MyClass(std::initializer_list<int> lst) {
        std::cout << "Calling initializer list constructor (conversion constructor)...\n";
        a = *(lst.begin());
        b = *(lst.begin() + 1);
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass &myclass_value) {
        std::cout << "Calling copy assignment operator...\n";
        a = myclass_value.a;
        b = myclass_value.b;

        return *this;
    }


    void display() {
        std::cout << "a = " << a
                << ", b = " << b << std::endl;
    }
};


int main(){
    MyClass object(10, 20);
    object.display();
 
    // Multiple parameterized conversion constructor is invoked.
    object = { 30, 40 };
    object.display();
    return 0;
}