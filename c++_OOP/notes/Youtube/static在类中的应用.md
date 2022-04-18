<font color="orange" size="4"><b>
`static` member:

- 在一个类声明 (class definition) 中，关键字 `static` 声明对象不是绑定于一个类实例 (bound to a class instance).
- 无论创建了多少个类的实例(object of class)，静态成员(static member)都只有一个副本(one copy)。一个static member被所有的类实例(object of class)共用。
- 在类定义(`class definition`)中，`static` 关键字仅在静态成员的声明(declaration of static member)时使用，而不在静态成员的定义(`definition` of static member)时使用
  - 类内只能声明静态成员 -- Inside class, declaration of static member
  - 类外才能定义静态成员 -- Outside class, definition of static member
</b></font>

<font size="4"><b>Syntax</b></font>

1. 静态成员的声明是指出 包含说明符包含关键字 `static` 的成员的声明。 
2. 关键字 `static` 通常出现在其他说明符之前。


# 1. Static data member
```c++
#include <iostream>


class Box {
private:
    double Length;  // Length of Box object
    double Breadth; // Breadth of Box object
    double Height;  // Height of Box object


public:
    static unsigned int ObjectCount;
    
    // Constructor function
    Box(double length, double breadth, double height) {
        std::cout << "Constructor is called...\n";
        Length = length;
        Breadth = breadth;
        Height = height;

        // Increase ObjectCount
        ObjectCount++;
    }

    double Volume() {
        return Length * Breadth * Height;
    }
};


// Initialize/definition of static member
unsigned int Box::ObjectCount = 0;


int main() {
    Box box1(3.3, 1.2, 1.5);    // Declare box1
    Box box2(8.5, 6.0, 2.0);    // Declare box2

    // Print total number of objects
    std::cout << "Total objects: " << Box::ObjectCount << std::endl;    // box1 and box2 share ObjectCount.
    return 0;
}
```


# 2. Static funtion member
<font color="orange" size="4"><b>
Notes:

- 即使不存在类的实例(object of class)，也可以通过 `::` 调用静态类成员函数(static class function member)
- static function member 只能访问以下几种数据：
  -  static data member
  -  其他的 static function member
  -  类外部的函数
</b></font>

```c++
#include <iostream>
 
using namespace std;

class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      static int getCount() {
         return objectCount;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   // Print total number of objects before creating object.
   cout << "Inital Stage Count: " << Box::getCount() << endl;

   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Box::getCount() << endl;

   return 0;
}
```