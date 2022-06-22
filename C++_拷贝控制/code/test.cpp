#include <iostream>
#include <cstring>


class String{
private:
    char *ptr_char;
    int size;


public:
    // Constructor function 1
    String() = default;

    // Constructor function 2
    /*
    Note
    ----
        1. const char *s = "Liuhanyu"; // right
        2. char *s = "Liuhanyu"; // wrong
    */
    String(const char *ptr_char_value) {
        std::cout << "Calling constructor...\n";

        size = strlen(ptr_char_value);
        // Note：给指针赋值之前，一定要给其分配内存空间
        // `strlen()` 函数不计算自动添加的 `\0`
        ptr_char = new char[size + 1];
        strcpy(ptr_char, ptr_char_value);
    }

    // Copy constructor function
    String(const String &string_value) {
        std::cout << "Calling copy constructor...\n";

        size = string_value.size;
        ptr_char = new char[size + 1];
        strcpy(ptr_char, string_value.ptr_char);
    }

    // Copy-assignment operator
    String& operator=(const String &string_value) {
        std::cout << "Calling copy-assignment operator...\n";

        size = string_value.size;
        ptr_char = new char[size + 1];
        strcpy(ptr_char, string_value.ptr_char);

        return *this;
    }

    // Destructor
    ~String() {
        std::cout << "Calling Destructor...\n";

        delete [] ptr_char;
    }

    // member function
    void change(const char *ptr_char_value) {
        size = strlen(ptr_char_value);
        ptr_char = new char[size + 1];
        strcpy(ptr_char, ptr_char_value);
    }

    friend std::ostream& operator<<(std::ostream&, String&);
};


/*
Note
----
    1. `operator<<` is a binary operator. 不能定义为 `member function`
    2. 类的 `member function` 第一个参数是隐式传递的 -- 指向本实例的指针 `this`
*/
// Overload `operator<<`
std::ostream& operator<<(std::ostream& COUT, String &string) {
    COUT << string.ptr_char << std::endl;
    return COUT;
}



// Driver code -- declare `deep copy`
int main() {
    String s_1("Liu Hanyu");    // Call constructor
    String s_2; 
    s_2 = s_1;    // Call copy-assignment operator
    std::cout << s_1;

    std::cout << "Intially:\n";
    std::cout << s_1;
    std::cout << s_2;

    std::cout << "\nChange the value of s_2...\n\n";
    s_2.change("Zhao Tong");

    std::cout << "Finally:\n";
    std::cout << s_1;
    std::cout << s_2;

    return 0;
}