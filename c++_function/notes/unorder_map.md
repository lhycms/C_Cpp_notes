## 1.1. 头文件 `include <unordered_map>`

哈希表

## 1.2. Example: 迭代器遍历 unordered_map

```c++
#include <iostream>
#include <string>
#include <unordered_map>


int main() 
{
    // 给 std::unordered_map<std::string, int> 起一个名字 ScoreMap
    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap map;
    map["Python"] = 5;
    map["C++"] = 2;


    // transverse the unordered_map with iterator
    for (ScoreMap::const_iterator it=map.begin(); it != map.end(); it++)
    {
        auto key = it->first;
        auto value = it->second;

        std::cout << key << " = " << value << std::endl;
    }
    std::cout << std::endl;

    // transverse the unordered_map with 范围for循环
    for (auto kv: map)
    {
        auto key = kv.first;
        auto value = kv.second;

        std::cout << key << " = " << value << std::endl;
    }
    std::cout << std::endl;

    // 必须使用 `-std=c++17`，才不会发出 warnings
    for (auto [key, value]: map)
        std::cout << key << " = " << value << std::endl;

    return 0;
}
```


# 2. `vector.erase(iterator_start, iterator_end)`
<font color="gree" size="4"><b>该函数使迭代器失效，并返回一个新的迭代器，新迭代器指向删除元素的下一个元素</b></font>


```c++
#include <iostream>
#include <vector>

int main()
{
    using VecInt = std::vector<int>;
    VecInt values{ 1, 2, 3, 4, 5, 6, 77 };

    for (VecInt::iterator it = values.begin();
        it != values.end(); )
    {
        if (*it == 3)
            it = values.erase(it);
        else 
            it++;
    }

    for (auto value: values)
        std::cout << value << " ";
    std::cout << std::endl;

    return 0;
}
```