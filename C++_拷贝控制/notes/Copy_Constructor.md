<!--
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-05-29 14:48:52
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-05-31 11:51:41
 * @FilePath: /C_C++/C++_拷贝控制/notes/Copy_Constructor.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# Copy constructor in C++
<font color="73DB90" size="4">

1. A `copy constructor` is a memeber function that intialize an object using another object of the same class.
2. A copy constructor has the following general function prototype:
```c++
ClassName (const ClassName &old_obj);
```

</font>


# 1. Demo 1. 拷贝构造函数的简单例子
```c++
// C++ program to demonstrate the working 
// of `copy constructor`
#include <iostream>


class Point {
private:
    float x, y;

public:
    // Constructor
    Point(float x1, float y1) {
        std::cout << "Calling constructor...\n";
        x = x1;
        y = y1;
    }

    // Copy Constructor
    Point(const Point &p1) {
        std::cout << "Calling copy constructor...\n";
        x = p1.x;
        y = p1.y;
    }

    // 友元函数: 运算符重载
    friend std::ostream& operator<<(std::ostream& COUT, Point& p);
};


// Reload Operation
std::ostream& operator<<(std::ostream& COUT, Point& p) {

    COUT << "x = " << p.x << std::endl;
    COUT << "y = " << p.y << std::endl;

    return COUT;
}


int main() {
    Point p_1(10, 15);  // 调用构造函数
    std::cout << p_1;

    Point p_2 = p_1;    // 构造拷贝构造函数
    std::cout << p_2;
    return 0;
}
```
Output:
```shell
$ g++ -Og -std=c++20 test.cpp -o test
$ ./test 
Calling constructor...
x = 10
y = 15
Calling copy constructor...
x = 10
y = 15
```


# 2. When is the copy constructor called?
<font color="73DB90" size="4">

In C++, a `Copy constructor` may be called in the following cases:
1. When an object of the class is returned by value(`not reference`).
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. <font color="orange">When the compiler generates a temporary object.</font>

</font>

<font color="red" size="4">

Note
----
1. It is, however, `not guaranteed that a copy constructor will be called in all these cases`, because the C++ Standard allows the compiler to optimize the copy away in certain cases, one example is the return value optimization (sometimes referred to as RVO).

</font>


# 3. Copy Elision
<font color="73BD90" size="4">

1. In `copy elision`, the `compiler` `prevents the making of extra copies` which results in saving the space and better the program complexity (`both time and space`); Hence making the code more optimized.

</font>


## 3.1. Demo 2. Copy Elision
```c++
// C++ program to demonstrate the working of copy elision
#include <iostream>


class GFG {

public:
    void print() {
        std::cout << "Hello Dear!!!\n";
    }

};


// Main Function
int main() {
    GFG g;
    for (size_t i = 0 ; i <= 2; i++ ) {
        g.print();
    }
    return 0;
}
```

Output:
```shell
$ g++ -Og std=c++20 test.cpp -o test
$ ./test
Case 1: 
      Hello Dear!
      Hello Dear!
      Hello Dear!

Case 2: 
      Hello Dear!
      Hello Dear!

Case 3: 
      Hello Dear!
```

<font color="73DB90" size="4">

Return Value Optimization (`RVO`)
---------------------------------
1. Now it is on the compiler to decide what it wants to print, it could either print the above output or it could print case 1 or case 2 below, and this is what `Return Value Optimization` is. 
2. In simple words, `RVO` is a technique that gives compiler some additional power to terminate the temporary object created which results in changing the observable behavior/characteristics of the final program.

</font>


# 4. When is a `user-defined copy constructor` needed?  `Shallow Copy` vs. `Deep Copy`
<font color="73DB90" size="4">

1. If we don't define our own copy constructor, the `C++ compiler` creates `a deafault copy  constructor for each class` which does a member-wise copy between objects.
2. We need to define our own copy constructor only if `an object has pointer or any runtime allocation of the resource`.
3. The defualt constructor does only `shallow copy`.
![shallow_copy](./pics/shallow_copy.png)
4. `Deep copy` is possible only with a `user-defined copy constructor`.
    - In a `user-defined copy constructor`, we make sure that `pointers (or references) of copied objects point to new memory locations`.  
![deep_copy](./pics/deep_copy.png)

</font>


# 5. `Copy constructor` vs. `Assignment Operator`
<font color="73DB90" size="4">

1. The main difference between `Copy Constructor` and `Assignment Operator`:
    - The `Copy constructor` makes `a new memory storage` every time it is called.
    - While the `assignment operator` does `not make new memory storage`.

</font>


## 5.1. When to call `Copy constructor` / `Assignment Operator`?

```c++
// Which of the following two statements calls the copy constructor and which one calls the assignment operator? 

MyClass t1, t2;
MyClass t3 = t1;    // Call constructor function
t2 = t1;    // Call assignment operator
```

<font color="73DB90" size="4">

1. A `copy constructor` is called when `a new object is created` from an existing object.
2. The `assignment operator` is called when an `already initialized object` is assigned.

</font>

# 6. Write an example class where a `copy constructor is needed`?   `Shallow Copy` vs. `Deep Copy`

## 6.1. Demo 1. 类中含有 `Copy Constructor` -- `Deep Copy`
Following is a complete C++ program to demonstrate the use of the Copy constructor. In the following String class, we must write a copy constructor. 

```c++
// C++ program to demostrate the 
// Working of Copy constructor
#include <iostream>
#include <cstring>


class String {
private:
    char *s;
    size_t size;

public:
    // Constructor
    String(char *s);

    // Copy Constructor 
    String(const String &);

    // Copy-assignment Operator
    String& operator=(const String&);

    // Desctructor
    ~String() { delete [] s; }

    // member function: print()
    void print();

    // member function: change()
    void change(const char*);
};


// Constructor
String::String(char *c) {
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
}


// Copy Constructor
String::String(const String &old_string) {
    size = old_string.size;
    s = new char[size + 1];
    strcpy(s, old_string.s);
}


// Copy-assignment Operator 
String& String::operator=(const String &old_string) {
    size = old_string.size;
    s = new char[size + 1];
    strcpy(s, old_string.s);
    return *this;
}


// member function: print()
void String::print() {
    std::cout << s << std::endl;
}


// member function: change()
void String::change(const char* c) {
    delete [] s;
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
}


int main() {
    String str1("GeeksQuiz");
    String str2 = str1;
 
    str1.print(); // what is printed ?
    str2.print();
 
    str2.change("GeeksforGeeks");
 
    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}
```

Output:
```shell
$ g++ -Og -std=c++20 test.cpp -o test
$ ./test
GeeksQuiz
GeeksQuiz
GeeksQuiz
GeeksforGeeks
```

## 6.2. Demo 2. 类中不含 `Copy Constructor` -- `Shallow copy`
<font color="orange" size="4">

What would be the problem if we remove the copy constructor from the above code? 
1. If we `remove the copy constructor` from the above program, we don’t get the expected output. The `changes made to str2 reflect in str1` as well which is never expected. 

</font>

```c++
#include <iostream>
#include <cstring>


class String {
private:
    char *s;
    size_t size;

public:
    // Constructor
    String(char *s);

    // Copy-assignment Operator
    String& operator=(const String&);

    // Desctructor
    ~String() { delete [] s; }

    // member function: print()
    void print();

    // member function: change()
    void change(const char*);
};


// Constructor
String::String(char *c) {
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
}



// Copy-assignment Operator 
String& String::operator=(const String &old_string) {
    size = old_string.size;
    s = new char[size + 1];
    strcpy(s, old_string.s);
    return *this;
}


// member function: print()
void String::print() {
    std::cout << s << std::endl;
}


// member function: change()
void String::change(const char* c) {
    delete [] s;
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
}


int main() {
    String str1("GeeksQuiz");
    String str2 = str1;
 
    str1.print(); // what is printed ?
    str2.print();
 
    str2.change("GeeksforGeeks");
 
    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}
```

Output:
```shell
$ g++ std=c++20 test.cpp -o test
$ ./test
GeeksQuiz
GeeksQuiz
GeeksforGeeks
GeeksforGeeks
test(35183,0x2024ab600) malloc: *** error for object 0x600002804040: pointer being freed was not allocated
test(35183,0x2024ab600) malloc: *** set a breakpoint in malloc_error_break to debug
[1]    35183 abort      ./test
```


# 7. Can we make the copy constructor `private`? 该类不能拷贝(The class become `non-copyable`)
<font color="73DB90" size="4">

1. Yes, a `copy constructor` can be made `private`. 
2. When we `make a copy constructor private` in a class, objects of that class become `non-copyable`. 
3. This is particularly useful `when our class has pointers or dynamically allocated resources`. 
4. In such situations, we can either write our own copy constructor like the above String example or make a private copy constructor so that users get compiler errors rather than surprises at runtime. 

</font>

```c++
#include <iostream>


class Point {
private:
    float x, y;

    // Copy Constructor
    Point(const Point &p1) {
        std::cout << "Calling copy constructor...\n";
        x = p1.x;
        y = p1.y;
    }

public:
    // Constructor
    Point(float x1, float y1) {
        std::cout << "Calling constructor...\n";
        x = x1;
        y = y1;
    }

    // 友元函数: 运算符重载
    friend std::ostream& operator<<(std::ostream& COUT, Point& p);
};


// Reload Operation
std::ostream& operator<<(std::ostream& COUT, Point& p) {

    COUT << "x = " << p.x << std::endl;
    COUT << "y = " << p.y << std::endl;

    return COUT;
}


int main() {
    Point p_1(10, 15);
    std::cout << p_1;

    Point p_2 = p_1;
    std::cout << p_2;
    return 0;
}
```
Output:
```shell
$ g++ -Og -Wall test.cpp -o test
$ ./test
test.cpp:42:17: error: calling a private constructor of class 'Point'
    Point p_2 = p_1;
                ^
test.cpp:9:5: note: declared private here
    Point(const Point &p1) {
    ^
1 error generated.
```


# 8. Why argument to a `copy constructor` must be passed `as a reference`? 
<font color="red" size="4">

Note
----
1. A `copy constructor` is called `when an object is passed by value`. Copy constructor itself is a function. 
2. `So if we pass an argument by value in a copy constructor`, a call to the copy constructor would be made to call the copy constructor which becomes a `non-terminating chain of calls`. Therefore compiler doesn’t allow parameters to be passed by value.
3. `拷贝构造函数的参数只能是引用(reference)`

</font>


# 9. Why `argument to a copy constructor` should be `const`?

## 9.1. Reason 1
<font color="73DB90" size="4">

1. One reason for passing const reference is, that we should use `const` in C++ wherever possible so that objects are not accidentally modified. 

</font>

## 9.2. Reason 2
https://www.geeksforgeeks.org/copy-constructor-argument-const/