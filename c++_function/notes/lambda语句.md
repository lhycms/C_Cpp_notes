# 解决方案一. `<algorithm> std::for_each()`
```c++
#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    struct {
        void operator() (int x) {
            std::cout << x << std::endl;
        }
    }something;

    std::vector<int> v{2, 3, 7, 14, 23};
    std::for_each(v.begin(), v.end(), something);

    return 0;
}
```

# 2. 解决方案二. `lambda` 语句
```c++
#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    std::vector<int> v{2, 3, 7, 14, 23};
    std::for_each(v.begin(), v.end(), [](int x){std::cout << x << std::endl;});

    return 0;
}
```

# 3. Demo_2 
```c++
#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::vector<int> v{2, 3, 7, 14, 23};
    std::for_each(v.begin(), v.end(), [](int x){
        if (x % 2 == 0)
            std::cout << x << " is even number.\n";
        else
            std::cout << x << " is odd number.\n";
    });

    return 0;
}
```

# 4. Demo_4
```c++
#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int d = 3; // to be captured by lambda
    std::vector<int> v{2, 3, 7, 14, 23};
    std::for_each(v.begin(), v.end(), [d](int x){
        if (x % d == 0)
            std::cout << x << " is divisible by " << d << std::endl;
        else
            std::cout << x <<  " is not divisible by " << d << std::endl;
    });

    return 0;
}
```


# 5. Demo_5: 改变 captured by lambda 的变量的值 (捕获多个变量)
```c++
#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int d = 3, e=4; // to be captured by lambda
    std::vector<int> v{2, 3, 7, 14, 23};
    std::for_each(v.begin(), v.end(), [&d, &e](int x){
        if (x % d == 0)
            std::cout << x << " is divisible by " << d << std::endl;
        else
            std::cout << x <<  " is not divisible by " << d << std::endl;
        d = 10;
        e = 5;
        std::cout << "After change d, d = " << d << std::endl;
        std::cout << "After change e, e = " << e << std::endl;
    });

    return 0;
}
```

# 6. 捕获所有变量
- `[=](...){...}`：不可改变变量的值
- `[&](...){...}`：可以改变变量的值