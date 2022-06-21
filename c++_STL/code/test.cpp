#include <iostream>
#include <algorithm>
#include <cmath>
#include <initializer_list>


class Coordination {
private:
    int x, y, z;

public:
    // Constructor 
    Coordination() = default;

    // Constructor
    Coordination(int x_value, int y_value, int z_value):
                        x(x_value), y(y_value), z(z_value)
    {   }


    // Copy Constructor
    Coordination(const Coordination& coordination) {
        x = coordination.x;
        y = coordination.y;
        z = coordination.z;
    }

    // Overloading copy assignment operator
    Coordination& operator=(Coordination &coordination) {
        x = coordination.x;
        y = coordination.y;
        z = coordination.z;

        return *this;
    }

    // Overload `<<`
    friend std::ostream& operator<<(std::ostream&, Coordination&);
    
    // Compare
    friend bool compareCoordination(Coordination&, Coordination&);
};


// Overload `<<`
std::ostream& operator<<(std::ostream& COUT, Coordination &c) {
    std::cout << "[" << c.x << ", " << c.y << ", " << c.z << "]" << std::endl;
    return COUT;
}


// Compare
bool compareCoordination(Coordination &c1, Coordination &c2) {
    float distance_1 = pow(c1.x, 2) + pow(c1.y, 2) + pow(c1.z, 2);
    float distance_2 = pow(c2.x, 2) + pow(c2.y, 2) + pow(c2.z, 2);
    return distance_1 < distance_2;
}

// show coordinations_lst
void show(Coordination cs_lst[], int cs_size) {
    for (int i=0; i<cs_size; i++) {
        std::cout << cs_lst[i];
    }
}


// Driver Code
int main() {
    Coordination cs_lst[] = { {9,2,3}, {7,7,7}, {6, 8, 10} };
    int cs_lst_size = sizeof(cs_lst) / sizeof(cs_lst[0]);
    show(cs_lst, cs_lst_size);

    return 0;
}