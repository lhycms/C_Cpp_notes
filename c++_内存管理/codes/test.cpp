#include <iostream>
#include <stdlib.h>


class Test {
private:
    int X;

public:
    // Constructor functions
    Test() {};
    Test(int x) {
        this->X = x;
    }

    // overload the new operator
    static void* operator new(size_t size, int value) {
        std::cout << "Allocate the space of "<< size << " bytes.\n";
        void *p = ::operator new(size);

        if (p != NULL)
            *p = value;
            // The above code is wrong because it is trying to dereference a pointer to a void.
        
        return p;
    }
};


int main() {
    Test *ptr = new(100) Test(0);
    delete ptr;
    return 0;
}