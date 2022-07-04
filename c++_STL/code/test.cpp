#include <iostream>

int main() {
    int a = 10;
    void *ptr = &a;

    std::cout << *static_cast<int*>(ptr) << std::endl;
    return 0;
}