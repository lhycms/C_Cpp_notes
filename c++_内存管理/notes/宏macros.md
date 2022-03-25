# 1. `#define` 定义宏 (macros)

```c++
// 宏可以定义为 函数/值
#define macro <some function/value>
```

## 1.1 Demo
```c++
#include <iostream>

#define PI 3.14
#define CIRC(d) (PI * d)


int main() {
    std::cout << "Please supply a diameter: ";
    int d;
    std::cin >> d;

    float circumference = CIRC(d);
    std::cout << "The circumference = " << circumference << std::endl;
    return  0;
}
```


# 2. `#ifdef`, `#ifndef`, `endif`
<font color="orange" size="4"><b>The preprocessor (`#ifdef`, `#ifndef`) will check if a macro has been predefined in the program.</b></font>

## 2.1. Demo
```c++
#include <iostream>

#define PI 3.14
#define CIRC(d) (PI * d)
#define DEBUG


int main() {
    #ifdef DEBUG
    std::cout << "In debug mode...\n";
    #endif

    std::cout << "Please supply a diameter: ";
    int d;
    std::cin >> d;

    float circumference = CIRC(d);
    std::cout << "The circumference = " << circumference << std::endl;
    return  0;
}
```