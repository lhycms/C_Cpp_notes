#include <bits/stdc++.h>
#include <exception>


struct MyException: public std::exception
{
    const char* what() const throw() {
        return "Overflow!\n";
    }
};


class StrLst {
public:
    typedef std::vector<std::string>::size_type size_type;

    // 构造函数
    StrLst() = default;
    StrLst(std::initializer_list<std::string> &lst);


    // empty(), size()
    bool empty() const { return ptr_data->empty(); }
    size_type size() const { return ptr_data->size(); }

    // 访问元素
    std::string& front();
    std::string& back();

    // 添加、删除元素
    void push_back(const std::string &str);
    void pop_back();

    // 友元函数
    friend std::ostream& operator<<(std::ostream &COUT, StrLst &str_lst);

private:
    // ptr_data 是一个指向 `vector<std::string>` 的指针
    std::shared_ptr< std::vector<std::string> > ptr_data;
    void check(size_type i);
};


// 构造函数
StrLst::StrLst(std::initializer_list<std::string> &lst): ptr_data(std::make_shared< std::vector<std::string> >(lst)) {};

// check 函数
void StrLst::check(size_type i) {
    if ( i > ptr_data->size() )
        throw MyException();
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
void StrLst::push_back(const std::string &str) {
    check(0);
    ptr_data->push_back(str);
}

void StrLst::pop_back() {
    check(0);
    ptr_data->pop_back();
}


// 运算符重载 -- `<<`
std::ostream& operator<<(std::ostream& COUT, StrLst &str_lst) {
    for (auto it=str_lst.ptr_data->begin();
        it != str_lst.ptr_data->end(); it++) {
        COUT << *it << "\t";
    }
    return COUT;
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