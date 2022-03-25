# 1. Usage
```c++
#include <stdlib.h>

int system(const char *command);
```

# 2. Example 2
```c++
#include <iostream>
#include <cstring>


int main(int argc, char **argv){
    char* str1 = argv[1];
    char* str2 = argv[2];
    // strcat(str1, str2): str1 = str1 + str2
    const char *cmd = strcat(str1, str2);
    system(cmd);
    return 0;
}                 
```