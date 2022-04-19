#include <bits/stdc++.h>


class Instrument {
public:
    virtual void make_sound() = 0;
};


class Accordion: public Instrument {
public:
    void make_sound() {
        std::cout << "Playing Accordion...\n";
    }
};


class Piano: public Instrument {
public:
    void make_sound() {
        std::cout << "Playing Piano...\n";
    }
};


int main() {
    Instrument* ptr_accordion = new Accordion();
    Instrument* ptr_piano = new Piano();

    Instrument* instruments_lst[] = {ptr_accordion, ptr_piano};

    for (auto ptr: instruments_lst)
        ptr->make_sound();

    return 0;
}