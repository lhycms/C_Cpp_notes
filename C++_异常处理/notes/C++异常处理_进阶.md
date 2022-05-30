<!--
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-04-17 11:32:28
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-05-29 10:44:28
-->
# 1. Demo 1
<font color="73DB90" size="4">

1. Following is a simple example to show exception handling in C++. The output of program explains flow of execution of `try/catch` blocks. 

</font>

```c++
#include <iostream>


int main() {
    int x = -1;

    // Some code
    std::cout << "Before try:\n";
    try {
        std::cout << "Inside try:\n";
        if ( x < 0 ) {
            throw x;
            std::cout << "After throw:\n";
        }
    } catch (int x){
        std::cout << "Exception Caught.\n";
    }
    std::cout << "After catch (Will be executaed) \n";

    return 0;
}
```
Output:
```shell
Before try:
Inside try:
Exception Caught.
After catch (Will be executaed) 
```


# 2. Demo 2
<font color="73DB90" size="4">

1. There is a special catch block called ‘catch all’ `catch(...)` that can be used to catch all types of exceptions.

</font>

```c++
#include <iostream>


int main() {
    try {
        throw 10;
    } catch (char *excp) {
        std::cout << "Caught: " << excp << std::endl;
    } catch (...) {
        std::cout << "Default Exception.\n";
    }
    return 0;
}
```

Output:
```shell
Default Exception.
```

# 3. Demo 3
<font color="73DB90" size="4">

1. Implicit type conversion doesn’t happen for primitive types. For example, in the following program `a` is not implicitly converted to int 

</font>

```c++
#include <iostream>


int main() {
    try {
        throw 'a';
    } catch (int x) {
        std::cout << "Caught" << x << std::endl;
    } catch (...) {
        std::cout << "Default Exception\n";
    }
    return 0;
}
```
Output:
```shell
Default Exception
```


# 4. Demo 4

<font color="73DB90" size="4">

1. If an exception is thrown and `not caught` anywhere, the program `terminates abnormally`. For example, in the following program, a char is thrown, but there is no catch block to catch a char.  

</font>

```c++
#include <iostream>


int main() {
    try {
        throw 'a';
    } catch (int x) {
        std::cout << "Caught" << x << std::endl;
    }
    return 0;
}
``` 
Output:
```shell
libc++abi: terminating with uncaught exception of type char
[1]    47885 abort      ./test
```


# 5. Demo 5: 退出代码块时，局部变量被释放
<font color="73DB90" size="4">

1. When an exception is thrown, all objects created inside the enclosing try block are `destructed` before the control is transferred to catch block.

</font>

```c++
#include <iostream>
using namespace std;
 
class Test {
public:
    // 构造函数
    Test() { cout << "Constructor of Test " << endl; }
    // 析构函数
    ~Test() { cout << "Destructor of Test " << endl; }
};
 
int main()
{
    try {
        Test t1;
        throw 10;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }
}
```

Output:
```shell
Constructor
Destructor
Caught 10
```


# 6. Demo 6: 编写 `std::exception` 的派生类
```c++
#include <iostream>
#include <exception>


class TestException: public std::exception {

public:
    // 构造函数
    TestException() {
        std::cout << "Constructor Function...\n";
    }

    // 析构函数
    ~TestException() {
        std::cout << "Destructor Function...\n";
    }


    const char* what() const throw() {
        return "Test Exception.\n";
    }

};


int main() {
    try {
        throw TestException();
    } catch (TestException& e) {
        std::cout << e.what();
    }

    return 0;
}
```

Output:
```shell
$ g++ -Og -std=c++20 test.cpp -o test
$ ./test
Constructor Function...
Test Exception.
1Destructor Function...
```