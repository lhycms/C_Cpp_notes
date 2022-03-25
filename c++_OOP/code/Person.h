#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
    std::string Name;
    std::string Address;

    // 定义Person的成员函数
    std::string getName() const;
    std::string getAddress() const;
};

// 类的接口：非成员函数的声明
std::ostream& print(std::ostream& os, Person& person);
std::istream& read(std::istream& is, const Person& person);


// 在类外定义类的成员函数
std::string Person::getName() const {
    return Name;
}

std::string Person::getAddress() const {
    return Address;
}

// 类的接口：非成员函数的定义
std::istream& read(std::istream& is, Person& person) {
    is >> person.Name >> person.Address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& person) {
    os << "Name: " << person.Name << std::endl;
    os << "Address: " << person.Address << std::endl;
    return os;
}

#endif