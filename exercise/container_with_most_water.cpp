//g++ -O3 container_with_most_water.cpp -o container_with_most_water.exe

#include <iostream>
#include<vector>
#include "container_with_most_water.hpp"

int main()
{
    std::vector<int> array;
    
    array.push_back(4);
    array.push_back(8);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(9);
    
    //array.push_back(5);
    int result = greatest_amount_two_pointers(array);

    std::cout << result << std::endl;

    return 0;
}