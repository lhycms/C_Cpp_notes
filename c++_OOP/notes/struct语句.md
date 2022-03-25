<font color="orange" size="4"><b>

C++数据类型：
1. 结构体(`struct`声明)
2. Basic/Built-in data type:
   - integer
   - float
   - double
   - character
   - and so on
  
</b></font>


# 1. Demo: 结构体 (`struct`语句) 的声明(declaration)与定义(definition)
```c++
#include <iostream>
#include <string>


// 结构体 declaration
struct SmartPhone {
    std::string name;
    int storage;
    std::string color;
    float price;
};

int main() {
    // 结构体 Initialization
    SmartPhone smartPhone;
    smartPhone.name = "Phone 12 pro";
    smartPhone.storage = 32;
    smartPhone.color = "color";
    smartPhone.price = 999.99;

    return 0;
}
```


# 2. Demo: 结构体(`struct`声明) 与 函数(functions)
```c++
#include <iostream>
#include <string>


struct SmartPhone {
    std::string name;
    int storage;
    std::string color;
    float price;
};


void printSmartPhoneInfo(SmartPhone smartPhone) {
    std::cout << "name: " << smartPhone.name << std::endl;
    std::cout << "storage: " << smartPhone.storage << std::endl;
    std::cout << "color: " << smartPhone.color << std::endl;
    std::cout << "price: " << smartPhone.price << std::endl;
}


int main() {
    SmartPhone smartPhone;
    smartPhone.name = "Phone 12 pro";
    smartPhone.storage = 32;
    smartPhone.color = "color";
    smartPhone.price = 999.99;

    SmartPhone smartPhone2;
    smartPhone2.name = "Samsung Galaxy S21 Ultra";
    smartPhone2.storage = 64;
    smartPhone2.color = "gray";
    smartPhone2.price = 888.88;

    printSmartPhoneInfo(smartPhone);
    printSmartPhoneInfo(smartPhone2);
    return 0;
}
```


# 3. Demo: 嵌套结构体 (Nested structure)
```c++
#include <iostream>
#include <string>


struct SmartPhone {
    std::string name;
    int storage;
    std::string color;
    float price;
};


// new code: Nested struct
struct Person {
    std::string name;
    int age;
    SmartPhone smartphone;
};


void printSmartPhoneInfo(SmartPhone smartPhone) {
    std::cout << "name: " << smartPhone.name << std::endl;
    std::cout << "storage: " << smartPhone.storage << std::endl;
    std::cout << "color: " << smartPhone.color << std::endl;
    std::cout << "price: " << smartPhone.price << std::endl;
}


void printPersonInfo(Person person) {
    std::cout << "name: " << person.name << std::endl;
    std::cout << "age: " << person.age << std::endl;
    std::cout << "smartphone info:\n";
    printSmartPhoneInfo(person.smartphone);
}


int main() {
    SmartPhone smartPhone;
    smartPhone.name = "Phone 12 pro";
    smartPhone.storage = 32;
    smartPhone.color = "color";
    smartPhone.price = 999.99;

    SmartPhone smartPhone2;
    smartPhone2.name = "Samsung Galaxy S21 Ultra";
    smartPhone2.storage = 64;
    smartPhone2.color = "gray";
    smartPhone2.price = 888.88;

    // new code: Nested struct
    Person p;
    p.name = "Saldina";
    p.age = 26;
    p.smartphone = smartPhone2;
    printPersonInfo(p);

    return 0;
}
```