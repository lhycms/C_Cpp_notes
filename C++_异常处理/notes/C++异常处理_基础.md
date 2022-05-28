<!--
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-04-17 10:33:40
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-05-28 15:57:00
-->
<font color="73DB90" size="4">

Exceptions provide a way to transfer control from one part of a program to anthor. C++ exception handling is built upon three keywords:
1. `throw`: A program throw a exception when a problem shows up. This is done using `throw` keyword.
2. `catch`: A program `catches an exception` with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.
3. `try`: A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

</font>

```c++
// Syntax
try {
    // protected code
} catch ( ExceptionName e1 ) {
    // catch block
} catch ( ExceptionName e2 ) {
    // catch block
} catch ( ExceptionName e3 ) {
    // catch block
}
```

# 1. `throw`: Throwing Exceptions
<font color="73DB90" size="4">

1. 可以使用 `throw` 语句在代码块内的任何地方抛出异常。 `throw` 语句的操作数确定异常的类型，可以是任何表达式，表达式结果的类型确定抛出的异常类型。

</font>

Following is an example of throwing an exception when dividing by zero condition occurs:
```c++
double division(int a, int b) {
    if ( b == 0 ) {
        throw "Divisiob by zero condition!\n";
    }
    return ( a/b );
}
```

# 2. `catch`: Catching Exceptions

## 2.1. `catch` 用法
<font color="73DB90" size="4">

1. `try` 块后面的 `catch` 块捕获任何异常。 您可以指定要捕获的异常类型，这取决于关键字 `catch` 后面括号中出现的异常声明。

</font>

```c++
try {
    // protected code
} catch ( ExceptionName e ) {
    // code to handle ExceptionName exception
}
```

# 2.2. Demo: `catch` 的用法
<font color="73DB90" size="4">

1. Because we are raising an `exception` of type `const char*`, so while catching this exception, we have to use `const char*` in catch block.

</font>

```c++
#include <iostream>


double divide(double a, double b) {
    if ( b == 0 )
        throw "Division by zero condition!\n";
    return (a / b);
}


int main() {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = divide(x, y);
        std::cout << z << std::endl;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}
```

Output:
```shell
Division by zero condition!
```


# 3. C+ Standard Exception
<font color="73DB90" size="4">

略

</font>


# 4. Define New Exception
<font color="73DB90" size="4">

1. You can define your own exception by inherting and overriding `exception` class functionality. 
2. Following is the example, which shows how you can use `std::exception` class to implement your own exception in standard way

</font>

## 4.1. Demo 1

<font color="73DB90" size="4">

1. Here, `what()` is a `public method provided by exception class` and it has been overridden by all the child exception classes. This returns the cause of an exception.
2. `const throw()`: 不是函数，这个东西叫做异常规格说明，表示`what()`函数可以抛出异常的类型，类型说明放在`()`里。这里面没有类型, 就是声明这个函数不抛出异常。

</font>

```c++
#include <iostream>
#include <exception>


struct MyException : public std::exception {

public:
    const char* what () const throw() {
        return "C++ Exception";
    }
    
};


int main() {
    try {
        throw MyException();
    } catch (MyException& e){
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;        
    } catch (std::exception& e) {
        // other errors
    }
    return 0;
}
```
Output:
```shell
MyException caught
C++ Exception
```


# 5. 异常规范 (`Exception Specifications`)
