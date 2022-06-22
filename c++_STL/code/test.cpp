/*
CPP program to implement `binary search` in STL 
*/
#include <iostream>
#include <algorithm>


void show(int array[], int array_size) {
    for (int i=0; i<array_size; i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}


int main() {
    int array[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int array_size = sizeof(array, array_size);
    std::cout << "The array is: \n";
    show(array, array_size);

    // Step 1. Sort the array. 
    std::cout << "Step 1, Sort the array: \n";
    std::sort(array, array + array_size);
    show(array, array_size);

    // Step 2. Search for 2, 10
    if ( std::binary_search(array, array+array_size, 2) )
        std::cout << "Element is found in array.\n";
    else
        std::cout << "Element is not found in array.\n";

    if ( std::binary_search(array, array+array_size, 10) )
        std::cout << "Element is found in array.\n";
    else
        std::cout << "Element is found in array.\n";

    return 0;
}