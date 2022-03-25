# 命名空间 (namespace)
```c++
#include <iostream>
/* 
    * std: a namespace which you use very often
        1. contains string, cout, endl
*/

// method 1: using namespace std; (This method is bad, because namespace std includes too many things.) 
/* method 2: using std::cout;
             using std::string;
             using std::endl;
*/
// method 3: use std::count in the code

namespace namespace1 {
    int age = 25;
    std::string name = "lhy";
}

namespace namespace2 {
    int age = 26;
}

int main() {
    std::cout << "age = " << namespace2::age << std::endl;
    return 0;
}
```