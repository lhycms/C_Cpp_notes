/*
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-06-04 17:46:29
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-06-06 20:04:21
 * @FilePath: /C_C++/c++_STL/code/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// C++ program to illustrate the 
// above concepts
#include <bits/stdc++.h>
#include <iostream>
#define N 3
#define M 3 


// Matrix class
class Matrix {
private:
    int arr[M][N];


public:
    // Overloading of input stream 
    friend std::istream& operator>>(std::istream&, Matrix&);

    // Overloading of output stream
    friend std::ostream& operator<<(std::ostream&, Matrix&);

    int& operator()(int, int);
};


// Function to overload the input ">>" operator
std::istream& operator>>(std::istream& CIN, Matrix &m) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Overloading operator()
            // to take input
            CIN >> m(i, j);
        }
    }
    return CIN;
}


// Function to overload the output "<<" operator
std::ostream& operator<<(std::ostream& COUT, Matrix &m) {
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Overloading operator() to
            // take input m.operator()(i,j)
            COUT << m(i, j) << "\t";
        }
        COUT << std::endl;
    }
    return COUT;
} 


// Function to call the operator
// function to overload the operators
int& Matrix::operator()(int i, int j) {
    return arr[i][j];
}


// Driver code
int main() {
    Matrix m;
    std::cout << "Input the matrix:\n";
    std::cin >> m;

    std::cout << "The matrix is:\n";
    std::cout << m;

    return 0;
}