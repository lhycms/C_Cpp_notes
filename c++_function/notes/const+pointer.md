# 情况 1
```c++
#include <iostream>


int main() {
    int value = 200;
    /*
        ptr 是一个可变指针
        ptr 指向了一个常量
    */
    const int *ptr = &value;
    return 0;
}
```

# 情况 2
```c++
#include <iostream>


int main() {
    int value = 200;
    /*
        ptr 是一个常量指针
        ptr 指向的值是可变的
    */
    int* const ptr = &value;
    return 0;
}
```

# 情况 3
```c++
#include <iostream>


int main() {
    int value = 200;
    /*
        ptr 是一个常量指针
        ptr 指向了一个常量      
    */
    const int* const ptr = &value;
    return 0;
}
```


# 1. 指针和 `constexpr`
必须明确一点，在 `constexpr` 声明中如果定义了一个指针，限定符 `constexpr` 仅对指针有效，与指针所指的对象无关。
```c++
const int* p = nullptr;     // p 是一个指向整型常量的指针
constexpr int *q = nullptr;     // q 是一个指向整数的常量指针

constexpr int i = 42;   // i的类型是整型常量
```