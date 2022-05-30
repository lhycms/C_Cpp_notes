<!--
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-05-29 16:43:07
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-05-30 17:46:36
 * @FilePath: /C_C++/C++_拷贝控制/notes/Copy_Elision.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# Copy Elision
<font color="73DB90" size="4">

`Copy elision` (or `Copy omission`) is a compiler optimization technique that `avoids unnecessary copying of objects`.

</font>

# 1. Demo 1.
```c++
#include <iostream>


class B {
public:
    // default constructor
    B(const char *str = NULL) {
        std::cout << "Constructor called.\n";
    }

    B(const B &b) {
        std::cout << "Copy constructor called.\n";
    }
};


int main() {
    B ob = "copy me";
    return 0;
}
```
Output:
```shell
$ g++ test.cpp -o test
Constructor called.
```


# 2. Why `copy constructor` is not called?  `temporary object`
<font color="73DB90" size="4">

1. According to theory, when the object `ob` is being constructed, `one argument constructor` is used to convert "copy me" to a `temporary object`.
2. That `temporary object` is copied to the object `ob`.
```c++
// So the statement
B ob = "copy me";

// should be broken down by the compiler as 
B ob = B("copy me");
```
3. However, most of C++ compilers avoid such overheads of creating a temporary object & then copying it.
```c++
// The modern compilers break down the statement
    B ob = "copy me"; //copy initialization

// as
    B ob("copy me"); //direct initialization

// and thus eliding call to `copy constructor`.

```
4. However, if we still want to ensure that the compiler doesn’t elide the call to copy constructor [`disable the copy elision`], we can compile the program using `“-fno-elide-constructors” option` with `g++` and see the output as following:
```shell
$ g++ -fno-elide-constructors test.cpp -o test
$ ./test
Constructor called
Copy constructor called
```
5. If `-fno-elide-constructors` option is used, 
    - first `default constructor` is called to `create a temporary object`
    - then `copy constructor` is called to copy the temporary object to ob.


</font>