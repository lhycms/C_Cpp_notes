#include <iostream>
#include <cstring>



class String {
private:
    char *s;
    size_t size;


public:
    // Constructor
    String() = default;
    String(const char*);

    // Copy Constructor
    String(const String&);

    // Copy-assignment operator
    String& operator=(const String&);

    // Destructor
    ~String() { delete [] s; }

    // member function
    void print();

    // member function
    void change(const char *);

};


// Constructor 
String::String(const char *c) {
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

// member function 
void String::print() {
    std::cout << "s = " << s << std::endl;
}

// member function 
void String::change(const char *c) {
    delete [] s;
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
}


int main() {
    String string_1 = String("Liu Hanyu");
    String string_2;
    string_2 = string_1;

    string_1.print();
    string_2.print();

    string_2.change("Zhao Tong");
    string_1.print();
    string_2.print();

    return 0;
}