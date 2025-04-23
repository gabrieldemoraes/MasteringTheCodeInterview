//g++ -O3 dfs_in_graphs.cpp -o dfs_in_graphs.exe

#include "dfs_in_graphs.hpp"
#include <iostream>

int main() {
    std::vector<std::vector<int>> adjacencyList = {
        {1, 3},
        {0},
        {3, 8},
        {0, 2, 4, 5},
        {3, 6},
        {3},
        {4, 7},
        {6},
        {2}
    };

    std::vector<int> values;
    std::unordered_set<int> seen;

    traversal_DFS(0, adjacencyList, values, seen);

    for (int value : values) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    return 0;
}