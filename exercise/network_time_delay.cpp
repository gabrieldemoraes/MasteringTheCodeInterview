//g++ -O3 network_time_delay.cpp -o network_time_delay.exe 

#include "network_time_delay.hpp"

#include <iostream>

int main() {
    vector<vector<int>> t = {{1, 2, 9}, {1, 4, 2}, {2, 5, 1}, {4, 2, 4}, {4, 5, 6}, {3, 2, 3}, {5, 3, 7}, {3, 1, 5}};
    cout << network_delay_time_bellman_ford(t, 5, 1) << endl;
    return 0;
} 