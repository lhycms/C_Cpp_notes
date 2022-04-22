#include <bits/stdc++.h>
#include <exception>


struct MyException: public std::exception {
    const char* what() const throw() {
        return "Overflow!";
    }
};


class StrLst {
public:
    typedef std::vector<std::string>::size_type size_type;

    // 构造函数
    StrLst() = default;
    StrLst(std::initializer_list<std::string> lst);

    // size(), empty()
    const size_type size() { return ptr_data->size(); }
    const bool empty() { return ptr_data->empty(); }

    // 访问元素
    std::string& front();
    std::string& back();

    // 添加、删除元素
    void push_back(std::string &str);
    void pop_back();

    // 友元函数 -- 运算符重载
    friend std::ostream& operator<<(std::ostream& COUT, StrLst &str_lst);

private:
    std::shared_ptr< std::vector<std::string> > ptr_data;
    void check(size_type i);
};

// private 成员函数
void StrLst::check(size_type i) {
    if ( i > ptr_data->size() )
        throw MyException();
}

// 成员函数 -- 构造函数
StrLst::StrLst(std::initializer_list<std::string> lst): ptr_data(std::make_shared< std::vector<std::string> >(lst)) { };

// 友元函数 -- 运算符重载
std::ostream& operator<<(std::ostream& COUT, StrLst &str_lst) {
    for (auto it = str_lst.ptr_data->begin();
            it != str_lst.ptr_data->end(); it++) {
        std::cout << (*it) << '\t';
    }
    return COUT;
}

// 成员函数 -- 访问元素
std::string& StrLst::front() {
    check(0);
    return ptr_data->front();
}

std::string& StrLst::back() {
    check(0);
    return ptr_data->back();
}


// 成员函数 -- 添加、删除元素
void StrLst::push_back(std::string &str) {
    check(0);
    ptr_data->push_back(str);
}

void StrLst::pop_back() {
    check(0);
    ptr_data->pop_back();
}


int main() {
    StrLst str_lst_1({"Liu", "Han", "Yu"});
    StrLst str_lst_2 = str_lst_1;

    std::cout << "Initially:\n";
    std::cout << str_lst_1 << std::endl;
    std::cout << str_lst_2 << std::endl;

    str_lst_1.pop_back();
    std::cout << "\nNow:\n";
    std::cout << str_lst_1 << std::endl;
    std::cout << str_lst_2 << std::endl;

    return 0;
}