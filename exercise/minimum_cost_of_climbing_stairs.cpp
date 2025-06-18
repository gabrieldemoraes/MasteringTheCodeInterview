//g++ -O3 minimum_cost_of_climbing_stairs.cpp -o minimum_cost_of_climbing_stairs.exe

#include "minimum_cost_of_climbing_stairs.hpp"
#include<iostream>

int main()
{
    std::vector<int> v = {20, 15, 30, 5};

    std::cout << min_cost_climbing_stairs(v) << std::endl;

    return 0;
}