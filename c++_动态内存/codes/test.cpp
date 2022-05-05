#include <bits/stdc++.h>
#include <memory>


// 向 vector 中输入 int
void input_vector(std::shared_ptr< std::vector<int> > ptr_vec) {
    int tmp_int;
    while (std::cin >> tmp_int) {
        ptr_vec->push_back(tmp_int);
    }
}

// std::cout 运算符重载
std::ostream& operator<<(std::ostream& COUT,
                        std::shared_ptr< std::vector<int> > ptr_vec) {
    for (auto value: *ptr_vec)
        COUT  << value << "\t";
    return COUT;
}


int main() {
    std::shared_ptr< std::vector<int> > ptr_vec = std::make_shared< std::vector<int> >();

    input_vector(ptr_vec);

    std::cout << ptr_vec << std::endl;

    return 0;
}