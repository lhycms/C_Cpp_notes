#include <bits/stdc++.h>


// Base Class
class YouTubeChannel {
public:
    // Constructor Function
    YouTubeChannel();
    YouTubeChannel(std::string name, std::string owner_name);

private:
    std::string Name;
    std::string OwnerName;
    unsigned int SubscribersCount;
};


// YouTubeChannel 构造函数
YouTubeChannel::YouTubeChannel(std::string name, std::string owner_name) {
    Name = name;
    OwnerName = owner_name;
    SubscribersCount = 0;
}


// Derived Class 1
class CookingYouTubeChannel: public YouTubeChannel {

public:
    CookingYouTubeChannel();
    CookingYouTubeChannel(std::string name, std::string owner_name): YouTubeChannel(name, owner_name) { };

    void practice() {
        std::cout << "Cooking...\n";
    }
};


// Derived Class 2
class SingingYouTubeChannel: public YouTubeChannel {

public:
    SingingYouTubeChannel();
    SingingYouTubeChannel(std::string name, std::string owner_name): YouTubeChannel(name, owner_name) { };

    void practice() {
        std::cout << "Singing...\n";
    }
};



// Main Function
int main() {
    auto ptr_cooking = std::make_shared<CookingYouTubeChannel>("Cooking", "Liu Hanyu");
    auto ptr_singing = std::make_shared<SingingYouTubeChannel>("Singing", "Liu Hanyu");
    
    ptr_cooking->practice();
    ptr_singing->practice();

    return 0;
}