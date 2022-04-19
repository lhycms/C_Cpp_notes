# 5. 多态 （polymorphisam）：修改 BaseClass 的类方法 -- 具有相同的名字，但具有不同的功能
<font color="orange" size="4"><b>
多态的例子：

- BaseClass: `YouTubeChannel`
- DerivecClass_1: `CookingChannel`
- DerivedClass_2: `SingersChannel`

两个 DerivedClass 的 `Practice()` 类方法的具体功能不同
</b></font>

```c++
#include <string>


class YouTubeChannel {
private:
    std::string Name;
    unsigned int SubscribersCount;
protected:
    std::string OwnerName;
public:
    YouTubeChannel(std::string name, std::string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }
};


// class declaration: CookingYouTubeChannel
class CookingYouTubeChannel: public YouTubeChannel {
public:
    CookingYouTubeChannel(std::string name, std::string ownername):YouTubeChannel(name, ownername) {

    }

    void Practice() {
        std::cout << "Practice cooking...\n";
    }
};


// class declaretion: SingersYouTubeChannel
class SingersYouTubeChannel: public YouTubeChannel {
public:
    SingersYouTubeChannel(std::string name, std::string ownername, unsigned int subscribersCount):YouTubeChannel(name, ownername, subscribersCount) {

    }

    void Practice() {
        std::cout << "Practice singing...\n";
    }
};
```



# 5.1. BaseClass 的指针可以指向 DerivedClass
```c++
CookingYouTubeChannel cookingytChannel("Hanyu's Kitchen", "Hanyu Liu")
YouTubeChannel *yt1 = &cookingytChannel;
```