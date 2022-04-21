#include <bits/stdc++.h>


/*
Part I
------
    Definition of `YouTubeChannel`
*/
class YouTubeChannel {
public:
    YouTubeChannel() = default;
    YouTubeChannel(std::string name, unsigned int subscribers_count);

    friend std::ostream& operator<<(std::ostream &COUT, YouTubeChannel &yt_channel);
    friend class MyCollection;

private:
    std::string Name;
    unsigned int SubscribersCount;
};

// 成员函数 -- 构造函数
YouTubeChannel::YouTubeChannel(std::string name, unsigned int subscribers_count) {
    Name = name;
    SubscribersCount = subscribers_count;
}

// 友元函数 -- 运算符`<<`重载
std::ostream& operator<<(std::ostream &COUT, YouTubeChannel &yt_channel) {
    COUT << "YouTubeChannel Object:\n";
    COUT << '\t' << yt_channel.Name << std::endl;
    COUT << '\t' << yt_channel.SubscribersCount << std::endl;
    
    return COUT;
}



/*
Part II
-------
    Definition of `MyCollection`
*/
class MyCollection {
public:
    MyCollection() = default;
    friend std::ostream& operator<<(std::ostream &COUT, MyCollection &my_collection);
    void operator+=(YouTubeChannel &yt_channel);

private:
    std::list<YouTubeChannel>  MyChannels;
};


// 友元函数 -- 运算符 `<<` 重载
std::ostream& operator<<(std::ostream &COUT, MyCollection &my_collection) {
    for (auto yt_channel: my_collection.MyChannels)
        std::cout << yt_channel;
    return COUT;
}

// 友元函数 -- 运算符重载 `+=` 重载
void MyCollection::operator+=(YouTubeChannel &yt_channel) {
    MyChannels.push_back(yt_channel);
}



/*
Part III
--------
    Main Function
*/
int main() {
    YouTubeChannel *ptr_yt_channel_1 = new YouTubeChannel("Programming", 203);
    YouTubeChannel *ptr_yt_channel_2 = new YouTubeChannel("Cooking", 1200);
    // std::cout << *ptr_yt_channel_1 << std::endl << *ptr_yt_channel_2;

    MyCollection *ptr_my_collection = new MyCollection();
    *ptr_my_collection += *ptr_yt_channel_1;
    *ptr_my_collection += *ptr_yt_channel_2;
    std::cout << *ptr_my_collection;


    delete ptr_yt_channel_1;
    delete ptr_yt_channel_2;
    delete ptr_my_collection;
    
    return 0;
}