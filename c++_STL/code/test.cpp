// Cpp Program to implement `std::bsearch()`
#include <bits/stdc++.h>


// Binary predicate
int compare(const void *ap, const void *bp) {
    // Typecasting
    const int *a = (int*)ap;
    const int *b = (int*)bp;

    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else 
        return 0;
}


// Driver code
int main() {
    // Given array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Size of array
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Element to be found
    int key1 = 4;

    // Calling `std::bsearch()`
    // Typecasting the returned pointer to int
    int *p1 = (int*)std::bsearch(&key1, arr, arr_size, sizeof(arr[0]), compare);

    // If non-zero value is returned, key is found
    if (p1)
        std::cout << key1 << " found at position " << (p1 - arr) << std::endl;
    else
        std::cout << key1 << " not found.\n";

    return 0;
}