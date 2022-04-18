# 类的简介
## 类的基本思想
<font color="green" size="4">

1. `数据抽象 (data abstraction)`：依赖于接口 (interface) 和实现 (implementation) 分离的编程技术
    - 类的`接口`：用户所能执行的操作
    - 类的`实现`：类的数据成员、负责接口实现的函数体、定义类所需要的各种私有函数
2. `封装 (encapsulation)`：实现了`接口`与`实现`的分离。
   - 主要作用：封装（隐藏）类的数据成员。

</font>

# 1. 简单的例子
```c++
#include <iostream>
#include <string>
#include <list>


class YouTubeChannel {
public: // You can get the attributes outside the class
    std::string Name;
    std::string OwnerName;
    unsigned int SubscribersCount;
    std::list<std::string> PublishedVideoTitles;
};


int main() {
    YouTubeChannel ytChannel;
    ytChannel.Name = "CodeBeaty";
    ytChannel.OwnerName = "Saldina";
    ytChannel.SubscribersCount = 1800;
    ytChannel.PublishedVideoTitles = {"C++ for beginners Video 1", "HTML & CSS Video 1", "C++ OOP Vedio 1"};

    std::cout << "Name: " << ytChannel.Name << std::endl;
    std::cout << "OwnerName: " << ytChannel.OwnerName << std::endl;
    std::cout << "SubscribersCount: " << ytChannel.SubscribersCount << std::endl;
    for (std::string videoTitle: ytChannel.PublishedVideoTitles) {
        std::cout << videoTitle << std::endl;
    } 

    return 0;
}
```


# 2. 构造函数 (Constructor Function) & 类方法 (Class Method)
<font size="4" color="orange"><b>构造函数的规则 (The rules of `Constructor Function`)</b></font>
1. Invoke the constructor function each time that you create a object of a class.
2. Constructor 函数具有与类相同的名字
3. Constructor 函数没有返回值
   
```c++
#include <iostream>
#include <string>
#include <list>


class YouTubeChannel {
public:
    std::string Name;
    std::string OwnerName;
    int SubscribersCount;
    std::list<std::string> PublishedVideoTitles;

    // Constructor Funtion
    YouTubeChannel(std::string name, std::string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }

    
    // Class method 
    void GetInfo() {
        // Output
        std::cout << "Name: " << Name << std::endl;
        std::cout << "OwnerName: " << OwnerName << std::endl;
        std::cout << "SubscriberCount: " << SubscribersCount << std::endl;
        std::cout << "Vedios:\n";
        for (std::string name: PublishedVideoTitles) {
            std::cout << name << std::endl;
    }
    }
};


int main() {
    // Declare and initialize the ytChannel
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.PublishedVideoTitles.push_back("C++ for beginners");
    ytChannel.PublishedVideoTitles.push_back("HTML & CSS");
    ytChannel.PublishedVideoTitles.push_back("C++ OOP");

    ytChannel.GetInfo();
    
    return 0;
}
```


# 3. 封装 (encapsulation): Outside class，不能直接修改 class attribute (`ytChannel.Name = "xxx"`)，而是用 class method 修改。
<font color="orange" size="4"><b>封装的规则 (The rules of encapsulation)</b></font>
1. 所有类属性( Class attribuete/properties ) 应该是 private 的，unaccessible outside the class.
2. 修改类属性的方法: expose public class methods 去修改 private class attributes/properties 

```c++
#include <iostream>
#include <string>
#include <list>


class YouTubeChannel {
private:    // 可以使用类方法改变private中的类属性 (private attribute of class)
    std::string Name;
    std::string OwnerName;
    int SubscribersCount;
    std::list<std::string> PublishedVideoTitles;

public:
    // Constructor Funtion
    YouTubeChannel(std::string name, std::string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }

    // Class method 
    void GetInfo() {
        // Output
        std::cout << "Name: " << Name << std::endl;
        std::cout << "OwnerName: " << OwnerName << std::endl;
        std::cout << "SubscriberCount: " << SubscribersCount << std::endl;
        std::cout << "Vedios:\n";
        for (std::string name: PublishedVideoTitles) {
            std::cout << name << std::endl;
    }
    }

    // Modify SubscibersCount
    void Subscribe() {
        SubscribersCount++;
    }
    void unsubscribe() {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }

    // Publish Video
    void PublishVideo(const std::string &title) {   // 避免使用拷贝赋值（用引用代替），若对象过大会消耗不必要的资源
        PublishedVideoTitles.push_back(title);
    }
};


int main() {
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.PublishVideo("C++ for beginners");
    ytChannel.PublishVideo("HTML & CSS");
    ytChannel.PublishVideo("C++ OOP");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();

    ytChannel.GetInfo();

    return 0;
}
```


# 4. 继承 (inheritance)




# Supplementary Material 1 -- 多线程调用类函数 (class function/method)
## S.1. 使用类函数初始化线程

<font color="orange" size="4"><b>Note: </b>
-   C++17之后才可以使用 `std::shared_mutex` 
-   传入 `std::thread()` 的参数分别为 线程函数、实例化类指针、函数参数</font>
  

## S.2. `.`, `::`, `:`, `->`
1. `object.attribute` -- object 为对象或结构体
2. `pointer->attribute` -- pointer 是指向类(class)、结构体(struct)、联合(union)的指针
3. `A::B` -- （作用域运算符）作用域A中的名称B，A可以是名字空间、类、结构
4. `:` -- 表继承

### S.2.1.
1. 类作用域：用来表明类的变量、函数
```c++
YouTubeChannel::Subscribe();
```
2. 空间作用域：用来注明所使用的类、函数属于哪一个命名空间的
```c++
std::cout << "Hello World" << std::endl;
```
3. 全局作用域
用来区分局部、全局的。最容易被忽视的一种，很多时候写了一个全局函数或者想要调用一个全局函数，却发现IDE或者Editor找不到该函数，原因是因为局部函数与想要调用的全局函数名字一样，然后找了很久也找不到原因，甚至放弃解决的。其实原因就是因为 【局部变量/函数】 与 【全局变量/函数】 的名字相同，IDE无法区分，这时候加上 `::` 就可以调用到全局函数，访问到全局变量了。

## S.3. Demo 
```c++
#include <thread>

class YouTubeChannel {

private:
    ...

public:
    // 类方法 (class method)
    void Subscibe() {
        ...
    }
};

// &YouTubeChannel::Subscribe 不需要传入参数
std::thread th1(&YouTubeChannel::Subscribe, &ytChannel);

/* joinable thead在程序结束前必须 
    1. th1.join() 
    2. th1.detach()
*/
th1.join()
```


```c++
#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <initializer_list>


class YouTubeChannel {
private:
    std::string Name;
    std::string OwnerName;
    unsigned int SubscibersCount;
    std::list<std::string> PublishedVideoTitles;

    // private shared mutex
    mutable std::shared_mutex Smtx;

public:
    // Constructor function
    YouTubeChannel(std::string name, std::string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscibersCount = 0;
    }

    // Subscribe function
    void Subscribe() {
        // get unique lock
        //std::unique_lock<std::shared_mutex> ul(Smtx);
        SubscibersCount++;
    }
    // Unsubcribe function
    void Unsubscribe() {
        // get unique lock 
        std::unique_lock<std::shared_mutex> ul(Smtx);
        if ( SubscibersCount > 0 )
            SubscibersCount--;
    }

    // Publish video
    void PublishVideo(std::initializer_list<std::string> videoTitles) {
        std::unique_lock<std::shared_mutex> ul(Smtx);
        for (auto begin = videoTitles.begin(); begin != videoTitles.end(); begin++) {
            PublishedVideoTitles.push_back(*begin);
        }
    }

    // Get Infomation
    void GetInfo() const{
        std::cout << "Name: " << Name << std::endl;
        std::cout << "OwnerName: " << OwnerName << std::endl;
        std::cout << "SubcribersCount: " << SubscibersCount << std::endl;
        std::cout << "Video:\n";
        for (std::string title: PublishedVideoTitles) {
            std::cout << title << std::endl;
        }
    }
};


int main() {
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    
    std::thread threadLst[200];

    for (int i=0; i<200; i++)
        // 传入顺序 线程函数，实例化类指针，函数参数
        // 注意：ytChannel一定要加 &，不加 & 就会变成拷贝赋值，拷贝对象时，会把 std::shared_mutex 也拷贝了从而引发错误
        threadLst[i] = std::thread(&YouTubeChannel::Subscribe, &ytChannel);

    for (auto &t: threadLst)
        t.join();

    ytChannel.GetInfo();
    return 0;
}
```


## S.4. 类成员函数初始化 thread + 可变参数 <initializer_list>

<font color="orange" size="3">

Note：不变的变量（常量）在definition时，最好加上 `const`，避免不必要的 bug

</font>

```c++
#include <iostream>
#include <string>
#include <list>
#include <initializer_list>
#include <mutex>
#include <shared_mutex>
#include <thread>


class YouTubeChannel {
private:
    std::string Name;
    std::string OwnerName;
    unsigned int SubscribersCount;
    std::list<std::string> PublishVideoTitles;

    mutable std::shared_mutex smtx;

public:
    YouTubeChannel(std::string name, std::string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }

    void GetInfo() const {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "OwnerName: " << OwnerName << std::endl;
        std::cout << "SubscribersCount: " << SubscribersCount << std::endl;
        for (const std::string title: PublishVideoTitles)
            std::cout << title << std::endl;
    }

    void Subscribe() {
        std::unique_lock<std::shared_mutex> ul(smtx);
        SubscribersCount++;
    }

    void UnSubscribe() {
        std::unique_lock<std::shared_mutex> ul(smtx);
        SubscribersCount--;
    }

    void PublishVideos(const std::initializer_list<std::string> &videoTitles) {
        std::unique_lock<std::shared_mutex> ul(smtx);
        for (std::initializer_list<std::string>::iterator it = videoTitles.begin();
                it != videoTitles.end(); it++) {
            PublishVideoTitles.push_back(*it);
        }
    }

    void PublishVideo(const std::string &videoTitle) {
        std::unique_lock<std::shared_mutex> ul(smtx);
        PublishVideoTitles.push_back(videoTitle);
    }
};


int main() {
    YouTubeChannel *ptr_ytChannel = new YouTubeChannel("CodeBeauty", "Saldina");
    ptr_ytChannel->GetInfo();

    std::thread th1(&YouTubeChannel::Subscribe, ptr_ytChannel);
    std::thread th2(&YouTubeChannel::Subscribe, ptr_ytChannel);
    std::initializer_list<std::string> lst = {"C++ for beiginner", "C++ OOP"};
    std::thread th3(&YouTubeChannel::PublishVideos, ptr_ytChannel, lst);

    th1.join();
    th2.join();
    th3.join();

    ptr_ytChannel->GetInfo();
    return EXIT_SUCCESS;
}
```


# 5. `Sales_data` 类的定义Demo -- C++ primer 例子
```c++
#include <iostream>
#include <string>


class Sales_data {
// 友元函数声明: 函数时类的接口的一部分，但不是类的成员（友元声明仅指定访问权限）
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);
    friend std::istream& read(std::istream&, Sales_data&);

private:
    // 数据成员
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;

public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned int n, double p):
        bookNo(s), units_sold(n), revenue(n*p) { }
    Sales_data(std::istream& is) {
        double price = 0.0;
        is >> bookNo >> units_sold >> price;
        this->revenue = units_sold * price;
    };

    // 成员函数
    std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};


// 需要对友元函数进行专门的函数声明
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

// 在类的外部定义成员函数
double Sales_data::avg_price() const {
    if (units_sold) 
        return revenue / units_sold;
    else 
        return 0;
}


// 在类的外部定义成员函数: 一个返回 this 对象的函数
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


// 类接口：非成员函数
std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}


// 类接口：非成员函数
std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " 
        << item.revenue << " " << item.avg_price();
    return os;
}


// 类接口：非成员函数
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


int main() {
    Sales_data item1("x-100", 50, 10);
    print(std::cout, item1);
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
```