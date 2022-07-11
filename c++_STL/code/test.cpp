#include <iostream>
#include <algorithm>


int compare(const void *p_1, const void *p_2) {
    const int *p1 = (int*)(p_1);
    const int *p2 = (int*)(p_2);

    if (*p1 > *p2)
        return 1;
    else if (*p1 < *p2)
        return -1;
    else
        return 0;
}


int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    std::sort(arr, arr+size);

    int *p1 = (int*)std::bsearch(&target, arr, size, sizeof(arr[0]), compare);

    if (p1)
        std::cout << "Found at " << (p1 - arr) << std::endl;
    else
        std::cout << "Not found.\n";

    return 0;
}