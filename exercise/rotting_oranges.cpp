//g++ -O3 rotting_oranges.cpp -o rotting_oranges.exe

#include "rotting_oranges.hpp"
#include <iostream>

int main()
{
    int matrix[4][5] = { { 2, 0, 1, 0, 0 },
                           { 1, 1, 0, 0, 2 },
                           { 0, 1, 1, 1, 1 },
                           { 0, 1, 0, 0, 1 } };


    auto response = oranges_rotting(matrix);

    std::cout << response << std::endl;

    return 0;
}