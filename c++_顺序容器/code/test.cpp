#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::vector<int> v = { 7, 3, 6, 2, 6};
    int key = 6;

    std::vector<int>::iterator itr = std::find(v.begin(),
                                            v.end(),
                                            key);

    if (itr != v.cend() ) {
        std::cout << "Element present at index: "
                << std::distance(v.begin(), itr)
                << std::endl;
    }                        
    else
        std::cout << "Not Found!!!\n";

    return 0;
}