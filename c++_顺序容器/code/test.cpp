#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>
#include <memory>


class StrBlob {

private:
    std::shared_ptr< std::vector<std::string> > data;
    // 如果 data[i] 不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;

public:
    typedef std::vector<std::string>::size_type size_type;
    
    // Constructor function
    StrBlob();
    StrBlob(std::initializer_list<std::string> i1);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    
    // 添加和删除元素
    void push_back(const std::string &t) { data->push_back(c); }
    void pop_back();

    // 元素访问
    std::string& front();
    std::string& back();
};


// StrBlob 构造函数
// 成员函数：可以 “类内部声明，外部定义”
StrBlob::StrBlob(): data(std::make_shared< std::vector<std::string> >() )  { }
// 接受一个 initializer_list 的构造函数，将其作为参数传递给对应的 vector 构造函数
StrBlob::StrBlob(std::initializer_list<std::string> i1): 
                data(std::make_shared< std::vector<std::string> >(i1)) { }


// 成员函数：check()
void StrBlob::check(size_type i, const std::string &msg) const {
    if ( i >= data->size() )
        std::cout << "Error!!!\n";
}


std::string& StrBlob::front() {
    // 如果 vector 为空，check 会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string& StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}