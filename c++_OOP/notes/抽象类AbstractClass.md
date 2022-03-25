# 1. Abstrct class Demo
<font color="orange" size="4"><b>抽象类(`AbstractClass`)的实现方式更有利于明确的分工，例如智能手机(`SmartPhone`)的开发可以分为以下三个开发部分。见以下的Demo</b></font>

```c++
#include <iostream>


/*
    Part I Code: 搭建手机的功能框架（描述手机大致有什么功能）-- Abstract class
*/
class SmartPhone {  // Abstract class
public:
    virtual void TakeASelfie() = 0; // Pure virual function
    virtual void MakeACall() = 0; // Pure virtual function
};


/*
    Part II Code: 不同手机的具体函数实现
*/
class Android:public SmartPhone {
public:
    void TakeASelfie() {
        std::cout << "Android selfie.\n";
    }

    void MakeACall() {
        std::cout << "Android calling.\n";
    }
};


/*
    Part III Code: 只需要知道 AbstrctClass 中的 virtual function 即可完成开发
*/

class Iphone:public SmartPhone {
public:
    void TakeASelfie() {
        std::cout << "Iphone selfie.\n";
    }

    void MakeACall() {
        std::cout << "Iphone calling.\n";
    }
};


int main() {
    SmartPhone *s1 = new Iphone();
    s1->TakeASelfie();
    s1->MakeACall();
    
    return 0;
}
```