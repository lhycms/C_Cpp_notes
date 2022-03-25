#include <iostream>
#include <string>
#include <vector>


class Screen {
public:
    typedef std::string::size_type pos;

    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd):
        height(ht), width(wd), contents(ht * wd, ' ');
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht * wd, c) { };

    // 函数成员
    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0;
};


inline 
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}  

Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    this->cursor = row + c;
    return *this;
}

void Screen::some_member() const {
    this->access_ctr++;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}