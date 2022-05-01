/*
 * @Author: your name
 * @Date: 2022-04-29 16:16:42
 * @LastEditTime: 2022-05-01 10:46:05
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /C_C++/c++_动态内存/codes/test.cpp
 */
#include <bits/stdc++.h>
#include <exception>


struct MyException : public std::exception {
    const char* what() const throw() {
        return "Overflow!!!";
    }
};


class StrLst {
private:
    std::shared_ptr<std::vector<std::string> > ptr_data;
    void check(int i);

public:
    typedef std::vector<std::string>::size_type size_type;
    // 构造函数 
    StrLst() = default;
    StrLst(std::initializer_list<std::string> str_lst);

    // 友元函数，运算符重载
    friend std::ostream& operator<<(std::ostream &COUT, StrLst &str_lst);

    // size(), empty()
    size_type size() { return ptr_data->size(); }
    bool empty() { return ptr_data->empty(); }

    // 查询元素 -- front(), back()
    std::string& front();
    std::string& back();

    // 添加、删除元素 -- push_back(), pop_back()
    void push_back(std::string str);
    void pop_back();
};


// private 成员函数 -- check
void StrLst::check(int i) {
    if ( i > ptr_data->size() )
        throw MyException();
}

// 构造函数
StrLst::StrLst(std::initializer_list<std::string> str_lst): ptr_data(std::make_shared< std::vector<std::string> >(str_lst)) { };

// 友元函数，运算符重载
std::ostream& operator<<(std::ostream &COUT, StrLst &str_lst) {
    for ( auto value: *(str_lst.ptr_data) )
        COUT << value << "\t";
    COUT << std::endl;
    return COUT;
}

// 成员函数 -- front()
std::string& StrLst::front() {
    this->check(1);
    return ptr_data->front();
}

// 成员函数 -- back()
std::string& StrLst::back() {
    this->check(1);
    return ptr_data->back();
}


// 成员函数 -- push_back()
void StrLst::push_back(std::string str) {
    this->check(1);
    ptr_data->push_back(str);
}

// 成员函数 -- pop_back()
void StrLst::pop_back() {
    this->check(1);
    ptr_data->pop_back();
}


int main() {
    std::initializer_list<std::string> lst{"Liu", "Han", "Yu"};
    StrLst strlst_1(lst);
    StrLst strlst_2 = strlst_1;

    std::cout << "初始化:\n";
    std::cout << strlst_1 << std::endl;
    std::cout << strlst_2 << std::endl;

    std::cout << "strlst_1 删除最后一个元素: \n";
    strlst_1.pop_back();
    std::cout << strlst_1 << std::endl;
    std::cout << strlst_2 << std::endl;
    return 0;
}