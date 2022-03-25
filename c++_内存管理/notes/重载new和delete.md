<font color="orange" size="4"><b>

`new`和`delete`操作符可以被重载：
- 全局重载 (be overloaded gloablly) -- Outside class definition
- 在特定类中重载 (be overloaded for specific classes) -- Inside class/struct definition
- 重载后的`new`和`delete`都是静态成员 (static members)

</b></font>


# 1. `new` 和 `delete` 语句

## 1.1. Syntax for overloading the `new` operator
```c++
void* operator new(size_t size);
```

- 重载的`new` operator需要一个参数 `size` (数据类型为`size_t`), <font color="gree">`size` 指明了分配内存空间的字节数目</font>
- <font color="gree">重载的`new` operator返回类型为 `void *`</font>
- The overloaded function returns a pointer to the beginning of the block of memory allocated.


# 1.2. Syntax for overloading the `delete` operator
```c++
void operator delete(void *);
```

- The function receives a parameter of type `void*` which has to be deleted. 
- `delete` 不返回任何 object


# 1.3. Demo 1 -- Overload `new` and `delete` inside class
<font color="gree" size="4"><b>注意：`new`和`delete`都是 operator</b></font>

```c++
#include <iostream>
#include <stdlib.h>


class Test {
private:
    int X;
public:
    Test() {}


    Test(int x) {
        X = x;
    }

    /*
        Overloaded new/delete operator is staic member automatically.
        So you can't access the pointer of this class object by `this->X`
    */
    static void *operator new(size_t size) {   
        std::cout << "Overloaded new operator size: " << size << std::endl;
        // malloc()函数返回的类型是 void*
        void *p = malloc(size);
        return p;
    }

    static void operator delete(void *p) {
        std::cout << "Overloaded Delete Operator." << std::endl;
        free(p);
    }
};


int main() {
    /*
        注意：调用 overloaded new operator时，并没有传入size。
        这是因为调用 new operator 时并不仅仅调用了 new。调用的其他部分计算了 size 并传入 new
    */
    Test *ptr = new Test();
    delete ptr;
    return 0;
}
```


# 2. Demo 1 -- Overloading new and delete operator for a specific class
```c++
#include <iostream>
#include <string>
#include <stdlib.h>


class Student {
private:
    std::string Name;
    int Age;

public:
    Student() {};
    Student(std::string name, int age) {
        this->Name = name;
        this->Age = age;
    }

    void display() {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Age: " << Age << std::endl;
    }

    static void * operator new(size_t size) {
        std::cout << "Allocate space " << size << " bytes.\n";
        void *p = ::operator new(size);

        return p;
    }


    static void operator delete(void *p) {
        std::cout << "Free the space.\n";
        free(p);
    }
};


int main() {
    Student *ptr = new Student("Hanyu Liu", 24);
    ptr->display();
    delete ptr;
    return 0;
}
```O

Output:
```shell
Allocate space of 40 bytes.
Name: Hanyu Liu
Age: 24
Free the space.
```

# 3. Demo 2 -- Global overloading of `new` and `delete` operator
```c++
#include <iostream>
#include <stdlib.h>


void * operator new(size_t size) {
    std::cout << "New operator overloading...\n";
    void *p = malloc(size);
    return p;
}

void operator delete(void *p) {
    std::cout << "Delete operator overloading...\n";
    free(p);
}


int main() {
    int *ptrIntLst = new int[3];
    /*
        数组的指针 ≈ 数组
    */
    for (int i = 0; i < 3; i++)
        *(ptrIntLst + i) = i;
    
    std::cout << "Array:\n";
    /*
        数组的指针 ≈ 数组
    */
    for (int i = 0; i < 3; i++)
        std::cout << ptrIntLst[i] << std::endl;
    
    delete ptrIntLst;
    return 0;
}
```

# 4. Demo 3 -- Why to overload new and delete? 

<font color="red" size="4"><b>不能对 `void *` 类型的指针进行 `dereference`.</b></font>

<font color="orange" size="4"><b>

1. 重载的`new`运算符函数可以接受参数。这为自定义对象(class object)的内存分配提供了更大的灵活性
2. 重载`new`和`delete` operator，为自定义对象(class object)提供了`垃圾收集(Garbage Collection)`
3. 可以在重载`new`和`delete` operator中添加`异常处理(Exception handling)`
4. 有时，您希望运算符 new 和 delete 执行编译器提供的版本不提供的自定义操作。 例如，您可以编写一个自定义操作符 delete，用零覆盖已释放的内存，以提高应用程序数据的安全性。
5. 我们可以在 new 函数中使用 `realloc()` 函数来动态重新分配内存。

</b></font>

