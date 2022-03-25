# 1. istringstream

## 1.1. Requirement
You must do thing as below before using istringsream
```c++
#include <sstream>

using std::istringstream;
```

# 1.2. Introduction
1. The `std::istringstream` is a string object which is used to stream the string into different variable, in particular, files can be stream into strings.
2. Object of this class use a <font color="red"><b>string buffer</b></font> that contains a sequence of characters.
3. This sequence of characters can be accessed as a string object.


## 1.3. Examples

###  1.3.1. Streaming integer from a string with `std::istringstream`
```c++
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

// Scope declaration
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;


// Main function
int main() {
    // string initialization
    string str("1 2 3");

    istringstream is(str);
    int value;
    while (is >> value) {
        cout << pow(value, 2) << endl;
    }
    return 0;
}
```


### 1.3.2 String with mixed types
```c++
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

// Scope declaration
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;


// Main function
int main() {
    // Input string
    string str("abc, def,   ghi");

    // Object of istringstream
    istringstream is(str);

    // Store the stream string.
    string token;

    size_t pos = -1;

    // Traberse till stream is valid 
    while (is >> token) {
        // if ',' is found in token 
        while ((pos = token.rfind(','))
                != string::npos)
            token.erase(pos, 1);
        
        cout << token << '\n';
    }
    return 0;
}
```


# 2. stringstream
https://www.geeksforgeeks.org/stringstream-c-applications/
## 2.1. Requirement

## 2.2. 