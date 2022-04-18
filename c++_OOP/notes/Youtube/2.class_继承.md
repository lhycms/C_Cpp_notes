# 4. 继承 (inheritance)

在C++继承中，we can derive a <font color="orange">child class</font> from the base class <font color="orange">in different access modes</font>.
- `public`
- `private`
- `protected`

## 使用方法
```c++
class BaseClass {
    ...
};

// access mode: public
class ChildClass: public Base {
    // 调用 BaseClass 的构造函数
    ChildClass(ChildClass构造函数的参数):BaseClass(BaseClass构造函数的参数) {
        ...
    }
};
```

## 4.1. Access Modes 特点
<font color="green" size="4"><b>`private` members of the `base class` are inaccessible to the `derived class`.</b></font>

1. `public`: 
    - `public` member -> `public` member
    - `protected` member -> `protected` member
2. `protected`:
    - `public` member -> `protected` member
    - `protected` member -> `protected` member
3. `private`:
    - `public` member -> `private` member
    - `protected` member -> `private` member

## 4.1.1. Access Mode 使用示例
```c++
class Base {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PrivateDerived
}
```


## 4.2. Public Demo
```c++
#include <iostream>


class BaseClass {
private:
    int Pvt = 1;

protected:
    int Prot = 2;

public:
    int Pub = 3;

    // function to access Pvt
    int GetPvt() {
        return Pvt;
    }
};


class PublishDerivedClass: public BaseClass {
public:
    int GetProt() {
        return Prot;
    }
};


int main() {
    PublishDerivedClass object;
    std::cout << "Private: " << object.GetPvt() << std::endl;
    std::cout << "Protected: " << object.GetProt() << std::endl;
    std::cout << "Published: " << object.Pub << std::endl;

    return 0;
}
```

## 4.3. Protected Demo
```c++
#include <iostream>


class BaseClass {
private:
    int Pvt = 1;

protected:
    int Prot = 2;

public:
    int Pub = 3;

    // function to access Pvt
    int GetPvt() {
        return Pvt;
    }
};


class PublishDerivedClass: protected BaseClass {
public:
    int GetProt() {
        return Prot;
    }

    int GetPub() {
        return Pub;
    }
};


int main() {
    PublishDerivedClass object;
    std::cout << "Private: " << "Private cann't be accessed." << std::endl;
    std::cout << "Protected: " << object.GetProt() << std::endl;
    std::cout << "Published: " << object.GetPub() << std::endl;

    return 0;
}
```

## 4.4. Private Demo
```c++
#include <iostream>


class BaseClass {
private:
    int Pvt = 1;

protected:
    int Prot = 2;

public:
    int Pub = 3;

    // function to access Pvt
    int GetPvt() {
        return Pvt;
    }
};


class PublishDerivedClass: private BaseClass {
public:
    int GetProt() {
        return Prot;
    }

    int GetPub() {
        return Pub;
    }
};


int main() {
    PublishDerivedClass object;
    std::cout << "Private: " << "Private cann't be accessed." << std::endl;
    std::cout << "Protected: " << object.GetProt() << std::endl;
    std::cout << "Published: " << object.GetPub() << std::endl;

    return 0;
}
```