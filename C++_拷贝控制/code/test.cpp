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