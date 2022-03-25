#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char **argv) {
    std::fstream myfile;
    std::vector<std::string> vector_str;
    std::string tmp_str;
    myfile.open("text.txt");
    if ( myfile ) {
        while ( myfile >> tmp_str ) {
            vector_str.push_back(tmp_str);
        }
    } 
    for (int i=0;i<40;i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    for (auto a: vector_str)
        std::cout << a << std::endl;
    return EXIT_SUCCESS;
}