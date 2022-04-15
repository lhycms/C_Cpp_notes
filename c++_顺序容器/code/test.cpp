#include <iostream>
#include <list>


int main() {
    // Declaring a list
    std::list<int> lst{};

    // using `assign()` to insert multiple numbers
    // creates 3 occurences of "2"(int)
    lst.assign(3, 2);

    // initializing list iterator to beginning
    std::list<int>::iterator it = lst.begin();

    // iterator to point to 3rd position
    std::advance(it, 2);

    // using insert to insert 1 element at 3rd position
    // inserts 5 at 3rd position
    lst.insert(it, 5);

    std::cout << "After first insert: \n";
    for (auto &value: lst)
        std::cout << value << "  ";
    std::cout << std::endl;

    // using insert to insert 2 element at 4th position
    // inserts 2 occurences of 7 at 4th position
    lst.insert(it, 2, 7);

    std::cout << "After second insert:\n";
    for (auto &value: lst)
        std::cout << value << "  ";
    std::cout << std::endl;

    return 0;
}