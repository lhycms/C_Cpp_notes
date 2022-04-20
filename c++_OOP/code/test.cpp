#include <bits/stdc++.h>


/*
Part I
------
    `YouTubeChannel` Definition
*/
class YouTubeChannel {
public:
    // Constructor Function
    YouTubeChannel() = default;
    YouTubeChannel(std::string name, unsigned int subscribers_count);

    std::string get_name();
    unsigned int get_subscribers_count();

    bool operator==(const YouTubeChannel &yt_channel) const {
        return (this->Name == yt_channel.Name);
    }


private:
    std::string Name;
    unsigned int SubscribersCount;
};


// 成员函数
YouTubeChannel::YouTubeChannel(std::string name, unsigned int subscribers_count): Name(name), SubscribersCount(subscribers_count) { };

// 成员函数
std::string YouTubeChannel::get_name() {
    return Name;
}

// 成员函数
unsigned int YouTubeChannel::get_subscribers_count() {
    return SubscribersCount;
}

// 运算符`<<`重载 -- 针对` YouTubeChannel`
std::ostream& operator<<(std::ostream& COUT, YouTubeChannel &yt_channel) {
    std::cout << yt_channel.get_name() << std::endl;
    std::cout << yt_channel.get_subscribers_count() << std::endl;
    return COUT;
}



/*
Part II
-------
    MyCollection Definition
*/
class MyCollection {
public:
    std::list<YouTubeChannel> my_channels;

    MyCollection() = default;

    void operator+=(YouTubeChannel &yt_channel);
    void operator-=(YouTubeChannel &yt_channel);
};

// 运算符重载
void MyCollection::operator+=(YouTubeChannel &yt_channel) {
    my_channels.push_back(yt_channel);
}

// 运算符重载
void MyCollection::operator-=(YouTubeChannel &yt_channel) {
    my_channels.remove(yt_channel);
}

// 运算符重载
std::ostream& operator<<(std::ostream &COUT, MyCollection &my_collection) {
    for (auto &yt_channel: my_collection.my_channels) 
        COUT << yt_channel;
    return COUT;
}


int main() {
    YouTubeChannel* ptr_yt_channel_1 = new YouTubeChannel("Programming_1", 24);
    YouTubeChannel* ptr_yt_channel_2 = new YouTubeChannel("Programming_2", 24);

    MyCollection *my_collection = new MyCollection();
    *my_collection += *ptr_yt_channel_1;
    *my_collection += *ptr_yt_channel_2;
    std::cout << "添加两个 channels 后, my_channels:\n";
    std::cout << *my_collection << std::endl;

    *my_collection -= *ptr_yt_channel_2;
    std::cout << "删除一个 channels 后, my_channels:\n";
    std::cout << *my_collection << std::endl;
    return 0;
}