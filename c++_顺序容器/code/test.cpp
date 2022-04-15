// CPP program to show the implementation of list
#include <bits/stdc++.h>


// function for printing the elements in a list
void showlist(std::list<int> &lst) {
    for (std::vector<int>::iterator it=lst.begin(); it != lst.end(); it++)
        std::cout << "\t" << (*it);
    std::cout << std::endl;
}


int main() {
    
    return 0;
}