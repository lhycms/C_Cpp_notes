#include <iostream>


class BaseClass {
private:
    int Pvt = 1;

protected:
    int Prot = 2;

public:
    int Pub = 3;

    // function to access Pvt
    int GetPvt() {
        return Pvt;
    }
};


class PublishDerivedClass: private BaseClass {
public:
    int GetProt() {
        return Prot;
    }

    int GetPub() {
        return Pub;
    }
};


int main() {
    PublishDerivedClass object;
    std::cout << "Private: " << "Private cann't be accessed." << std::endl;
    std::cout << "Protected: " << object.GetProt() << std::endl;
    std::cout << "Published: " << object.GetPub() << std::endl;

    return 0;
}