#include <bits/stdc++.h>


int main() {
    std::vector<int> arr{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = arr.size();

    std::sort(arr.begin(), arr.end());

    for (auto &value: arr) 
        std::cout << value << "  ";
    return 0;
}