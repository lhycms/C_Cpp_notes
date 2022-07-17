#include <iostream>
#include <algorithm>


int compare(const void* ptr_1, const void* ptr_2) {
    const int *p1 = (int*)ptr_1;
    const int *p2 = (int*)ptr_2;

    if (*p1 > *p2)
        return 1;
    else if (*p1 < *p2)
        return -1;
    else
        return 0;
}


int main() {
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    std::sort(arr, arr + size);
    
    int *p_found = (int*)std::bsearch(&key, arr, size, sizeof(arr[0]), compare);
    if (p_found)
        std::cout << key << " is found at position " << (p_found - arr) << std::endl;
    else
        std::cout << key << " is not found in arr.\n";
    return 0;
}