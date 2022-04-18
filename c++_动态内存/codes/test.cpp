#include <bits/stdc++.h>
#include <initializer_list>
#include <exception>


struct MyException : public std::exception {
    const char* what() const throw() {
        return "Overflow!";
    }
};


class StrBlob {

public:
    typedef std::vector<std::string>::size_type size_type;

    // Constructor 
    StrBlob();
    StrBlob(std::initializer_list<std::string> &i1);

    // empty() and size()
    bool empty() const { return data->empty(); }
    size_type size() const { return data->size(); }

    // 访问元素
    std::string& front();
    std::string& back();

    // 添加、删除元素
    void push_back(const std::string& str);
    void pop_back();

    // 输出所有元素的指针值（在内存中的地址）
    void print_ptrs() {
        for (auto tmp_ptr=data.get(); tmp_ptr < data.get() + data->size(); tmp_ptr++)
            // 遍历 STL 容器的值的时候，切忌使用指针
            std::cout << tmp_ptr << "  ";
        std::cout << std::endl;
    }

    // 输出所有元素的值
    void print_elements() {
        for (auto tmp_it=data->begin(); tmp_it < data->end(); tmp_it++)
            std::cout << *tmp_it << "  ";
        std::cout << std::endl;
    }

private:
    std::shared_ptr< std::vector<std::string> > data;
    // 若 i->&i，则不能传数值，所以此处不能用引用
    void check(size_type i) const;
};

// 构造函数
// Note: 一定不要忘记写空的函数体
StrBlob::StrBlob(): data(std::make_shared< std::vector<std::string> >()) { };
StrBlob::StrBlob(std::initializer_list<std::string> &i1): data(std::make_shared< std::vector<std::string> >(i1)) { };

// check function
void StrBlob::check(size_type i) const {
    if ( i > data->size() )
        throw MyException();
}

// 访问元素
std::string& StrBlob::front() {
    check(0);
    return data->front();
}

std::string& StrBlob::back() {
    check(0);
    return data->back();
}

// 添加、删除元素
void StrBlob::push_back(const std::string &str) {
    check(0);
    data->push_back(str);
}

void StrBlob::pop_back() {
    check(0);
    data->pop_back();
}


// Main function
int main() {
    std::initializer_list<std::string> lst = {"Liu", "Han", "Yu"};
    StrBlob lst_1 = StrBlob(lst);
    StrBlob lst_2 = lst_1;
    std::cout << "lst_1: \n";
    lst_1.print_elements();
    std::cout << "lst_2: \n";
    lst_2.print_elements();

    std::cout << "\nlst_1 删除 'Yu' 后:\n";
    lst_1.pop_back();    std::cout << "lst_1: \n";
    lst_1.print_elements();
    std::cout << "lst_2: \n";
    lst_2.print_elements();
    return 0;
}