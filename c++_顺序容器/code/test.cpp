#include <iostream>

void output_version1(int (&a)[3][4]);
void output_version2(int (&a)[3][4]);
void output_version3(int (&a)[3][4]);

int ia[3][4] = { {0, 1, 2, 3},
                 {4, 5, 6, 7},
                 {8, 9, 10, 11} };

int main() {
    output_version2(ia);
    return EXIT_SUCCESS;
}

void output_version1(int (&a)[3][4]) {
    for (int (&row)[4]: a) {
        for (int (&col): row) {
            std::cout << col << ' ';
        }
        std::cout << std::endl;
    }    
}

void output_version2(int (&a)[3][4]) {
    int rowCnt = 3;
    int colCnt = 4;

    for (int i=0; i<rowCnt; i++) {
        for (int j=0; j<colCnt; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


void output_version3(int (&a)[3][4]) {
    for (int (*row)[4]=std::begin(a); row<a+3; row++) {
        for (int *col=std::begin(*row); col<(*row)+4; col++) {
            std::cout << *col << ' ';
        }
        std::cout << std::endl;
    }
}