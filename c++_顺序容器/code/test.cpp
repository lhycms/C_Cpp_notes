#include <bits/stdc++.h>


void find_all_key(std::vector<int>&, int&, std::vector<size_t>&);


int main() {
    std::vector<int> ints_lst = { 10, 20, 30, 40 };
    int key = 20;
    std::vector<size_t> indexes_lst{};

    find_all_key(ints_lst, key, indexes_lst);

    for (auto &value: indexes_lst) {
        std::cout << value << "  ";
    }
    std::cout << std::endl;

    return 0;
}


void find_all_key(std::vector<int> &ints_lst, int &key, std::vector<size_t> &indexes_lst) {
    int tmp_index = 0;
    std::vector<int>::iterator tmp_it_int = ints_lst.begin();

    while ( tmp_it_int != ints_lst.end() ) {
        tmp_it_int = std::find(tmp_it_int, ints_lst.end(), key);
        tmp_index = std::distance(ints_lst.begin(), tmp_it_int);
        indexes_lst.push_back(tmp_index);
        tmp_it_int += 1;
    }
}