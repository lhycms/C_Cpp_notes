#include <iostream>

int main(int argc, char **argv) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int *e = &arr[10];

    for (int *b=arr; b!=e; b++) {
        std::cout << *b << std::endl;
    }

    return EXIT_SUCCESS;
}