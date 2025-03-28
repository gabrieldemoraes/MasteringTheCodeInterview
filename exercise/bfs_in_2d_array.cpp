//g++ -O3 bfs_in_2d_array.cpp -o bfs_in_2d_array.exe

#include "bfs_in_2d_array.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>


int main()
{
    int matrix[4][5] = { { 1, 2, 3, 4, 5 },
                           { 6, 7, 8, 9, 10 },
                           { 11, 12, 13, 14, 15 },
                           { 16, 17, 18, 19, 20 } };

    bool visit[4][5];
    memset(visit, false, sizeof visit);                        

    std::vector<int> values;

    BFS(matrix, 0, 0, visit, values);

    for(int i = 0; i < values.size(); ++i)
        std::cout << values[i] << std::endl;

}