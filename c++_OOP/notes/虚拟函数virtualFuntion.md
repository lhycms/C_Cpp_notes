# 1. Virtual Function

## 1.1. Virtual funtion 定义
Virtual function 是在 BaseClass 中定义，并在 DerivedClass 中重新定义（覆盖）的成员函数。当你使用以下两种方式：
- 基类指针
- 基类的引用

去引用 DerivedClass object时，可以执行 Virtual function（BaseClass中定义的版本）

<font color="orange" size="4"><b>
Note:

- Virtual functions ensure that the correct functions is called for an object, regardless of the type of `reference/pointer` used for function call.
- Virtual function is used to achieve 多态
- 基类中的 Virtual function 定义，需要使用 `virtual` 关键字
</b></font>


## 1.2. Rules of virtual functions
1. Virtual function 不能使用 `static`
2. A virtual function can be a friend function of another class.
3. 可以使用 BaseClass 的引用和指针调用 Virtual function（运行BaseClass中的函数），以实现多态
4. BaseClass 和 DerivedClass 中 Virtual function 的 原型(prototype) 应该一致


## 1.3. Compile-time(early binding) VS. run-time(late binding) behavior of Virtual Functions

<font color="gree" size="4"><b>
说明：

- 运行时的多态(Runtime polymorphism)只能通过`基类指针/引用(BaseClass pointer/reference)`来实现。-- BaseClass 指针既可以指向 BaseClass objcet 也可以指向 DerivedClass object。
- Binding 时间：
  - Compile-time (early binding): 根据指针的类型进行。没有 `virtual`声明的 BaseClass 函数
  - <font color="red" size="4"><b>Run-time (late binding): 根据指针指向的内容进行。`virtual`声明的 BaseClass 函数</b></font>
</b></font>



# 2. Virtual Funtion Demo
```c++
#include <iostream>

class Instrument {
public:
    virtual void MakeSound() {  // Binding when Run-time
        std::cout << "Instrument playing...\n";
    }
};

class Accordion:public Instrument {
public:
    void MakeSound() {
        std::cout << "Accordion playing...\n";
    }
};


int main(){
    Instrument *i1 = new Accordion();
    i1->MakeSound();

    return 0;
}
```


# 2. Pure Virtual Function & Abstract Class
<font color="orange" size="4"><b>
在下面例子中 :

- `MakeSound()` 是 Pure virtual function，它的 DerivedClass 必须有同名pure virtual function的实现。
- `Instrument` 是 Abstract class
</b></font>
  
```c++
#include <iostream>


// Base class: Instrument -- Abstract class
class Instrument {
public:
    virtual void MakeSound() = 0;   // Pure virtual function
};

// Derived class: Accordion
class Accordion:public Instrument {
public:
    void MakeSound() {
        std::cout << "Accordion playing...\n";
    }
};

// Derived class: Piano
class Piano:public Instrument {
public:
    void MakeSound() {
        std::cout << "Piano playing...\n";
    }
};


int main(){
    Instrument *i1 = new Accordion();
    Instrument *i2 = new Piano();

    i1->MakeSound();
    i2->MakeSound();

    return 0;
}
```


# 3. 多态 (Polymorphisam)
```c++
#include <iostream>


// Base class: Instrument -- Abstract class
class Instrument {
public:
    virtual void MakeSound() = 0;   // Pure virtual function
};

// Derived class: Accordion
class Accordion:public Instrument {
public:
    void MakeSound() {
        std::cout << "Accordion playing...\n";
    }
};

// Derived class: Piano
class Piano:public Instrument {
public:
    void MakeSound() {
        std::cout << "Piano playing...\n";
    }
};


int main(){
    Instrument *i1 = new Accordion();
    Instrument *i2 = new Piano();

    Instrument* instrumentsLst = { i1, i2 };
    for (auto instrument: instrumentsLst) 
        instrument->MakeSound()


    return 0;
}
```