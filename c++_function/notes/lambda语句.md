<!--
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-04-29 16:16:42
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-06-23 15:26:02
 * @FilePath: /C_C++/c++_function/notes/lambda语句.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# `Lambda Expression` 是 C++ 引入的一个语法糖，可以方便快捷地创建一个`函数对象`
1. 从 `C++11` 开始，C++ 有以下三种方式可以创建/传递一个可以被调用的对象
    - `函数指针`
    - `仿函数（Functor）`
    - `Lambda 表达式`

# 1. 函数指针
<font color="red" size="4">

Note
----
1. `函数指针`是什么东西？

</font>

1. 函数指针是从 C 语言继承的，有以下缺点：
    1. 无法直接捕获当前的一些状态，所有外部状态只能通过参数传递（不考虑在函数内部使用 `static`）
    2. 使用函数指针的调用无法 `inline` (编译期无法确定这个指针会被赋什么值)
```shell
// 一个指向有两个整型参数，返回值为整型参数的函数指针类型
int (*)(int, int);

// 通常我们用 typedef 来定义函数指针类型的别名方便使用
typedef int (*Plus)(int, int);

// 从 C++11 开始，更推荐使用 using 来定义别名
using Plus = int (*)(int, int);
```

# 2. 仿函数 `Functor`
1. `仿函数` 就是让一个`类 (class/struct)`的对象的使用上像一个函数，具体实现就是在类中 `重载 operator()`
2. 相比于 `函数指针`，仿函数对象可通过成员变量捕获/传递一些状态。
3. 实例化后，通过 `object()` 调用
```c++
class Plus {
public:
    int operator()(int a, int b) {
        return a + b;
    }
}

int main {
    Plus plus;  // 实例化后，才能调用 Functor
    std::cout << plus(11, 22) << std::endl; // 输出 33
}
```


# 3. `lambda` 语句
1. C++ 11 introduced `lambda expression` to allow us write an `inline function (内联函数)` which can be used for short snippets of code that are `not going to be reuse and not worth naming`. In its simplest form lambda expression can be defined as follows: 
```c++
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
} 
```
2. Generally `return-type in lambda expression` are evaluated by compiler itself and we don’t need to specify that explicitly and `-> return-type part can be ignored` but in some complex case as in conditional statement, compiler can’t make out the return type and we need to specify that. 

## 3.1. Demo 1
