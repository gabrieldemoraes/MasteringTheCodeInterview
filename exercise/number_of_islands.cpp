//g++ -O3 number_of_islands.cpp -o number_of_islands.exe
#include "number_of_islands.hpp"
#include "iostream"

int main()
{
    int matrix[4][5] = { { 1, 1, 1, 0, 0 },
                           { 1, 1, 1, 0, 1 },
                           { 0, 1, 0, 0, 1 },
                           { 0, 0, 0, 1, 1 } };


    auto response = number_of_islands_DFS(matrix);

    std::cout << response << std::endl;


    return 0;
}